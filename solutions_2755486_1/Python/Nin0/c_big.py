#!/usr/bin/python3

import sys
import collections

T = int(sys.stdin.readline())
caseNum = 0

class Drevo:
    def __init__(self, left, right, min_h):
        self.left = left
        self.right = right
        self.min_h = 0
        self.left_child = None
        self.right_child = None
    
    def success(self, left, right, strength):
        if (self.left == self.right):
            return strength > self.min_h
        if self.min_h > strength:
            return False
        middle = (self.left + self.right) // 2
        if (left == self.left) and (right == self.right):
            return self.min_h < strength
        if self.left_child is None:
            self.left_child = Drevo(self.left, middle, self.min_h)
        if self.right_child is None:
            self.right_child = Drevo(middle+1, self.right, self.min_h)
        if left <= middle:
            ans = self.left_child.success(left, middle, strength)
            if ans: return True
        if right >= middle+1:
            ans = self.right_child.success(middle+1, right, strength)
            if ans: return True
        return False
    
    def repair(self, left, right, strength):
        if (self.left == self.right):
            self.min_h = strength
            return
        middle = (self.left + self.right) // 2
        if (left == self.left) and (right == self.right):
            self.min_h = max(self.min_h, strength)
            return
        if self.left_child is None:
            self.left_child = Drevo(self.left, middle, self.min_h)
        if self.right_child is None:
            self.right_child = Drevo(middle+1, self.right, self.min_h)
        if left <= middle:
            self.left_child.repair(left, middle, strength)
        if right >= middle+1:
            self.right_child.repair(middle+1, right, strength)
        self.min_h = min(self.left_child.min_h, self.right_child.min_h)

def repair(left, right, strength):
    global zid
    zid.repair(left, right, strength)
    
def success(left, right, strength):
    global zid
    return 1 if zid.success(left, right, strength) else 0
        
def solve(tribe_data):
    # print(tribe_data)
    global zid
    zid = Drevo(0, 2**28-1, 0)
    events = [] # list of events
    OFFSET = 101000000
    for d, n, w, e, s, dd, dp, ds in tribe_data:
        for i in range(n):
            events.append( (d + i*dd, w+i*dp+OFFSET, e+i*dp+OFFSET-1, s+i*ds, "attack") )
            events.append( (d + i*dd + 0.5, w+i*dp+OFFSET, e+i*dp+OFFSET-1, s+i*ds, "repair") )
    events.sort()
    succ = 0
    for time, left, right, strength, mode in events:
        if mode == 'repair':
            repair(left, right, strength)
        else:
            # mode == 'attack'
            succ += success(left, right, strength)
    return succ

while caseNum < T:
    caseNum += 1
    N = int(sys.stdin.readline())
    tribe_data = []
    for i in range(N):
        tribe_data.append( tuple(map(int, sys.stdin.readline().strip().split(' '))) )
    print("Case #{0}: {1}".format(caseNum, solve(tribe_data)))
