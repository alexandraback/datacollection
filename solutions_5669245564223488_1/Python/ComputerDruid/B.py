#!/usr/bin/env python
from collections import defaultdict

MOD = 1000000007

def modfact(n):
    result = 1
    while n > 0:
        result = (result * n%MOD) % MOD
        n -= 1
    return result

def uniq(s):
    last = None
    used = set()
    built = []
    for c in s:
        if c != last:
            if c in used:
                return None
            used.add(c)
            built.append(c)
            last = c
    return "".join(built)

class Problem:
    def take_single(self, c):
        self.single[c] += 1
        if self.solo[c]:
            return False
        return True
    def take_solo(self,c):
        if self.solo[c]:
            return False
        if c in self.left:
            return False
        if c in self.right:
            return False
        if self.single[c] > 0:
            return False
        self.solo[c] = True
        return True
    def take_pair(self,c_left, c_right):
        if c_left in self.left:
            return False
        if c_right in self.right:
            return False
        if self.solo[c_left] or self.solo[c_right]:
            return False
        self.left[c_left] = c_right
        self.right[c_right] = c_left
        return True

    def check_loops(self):
        reachable = set()
        for c in self.starts:
            while c in self.left:
                assert c not in reachable
                reachable.add(c)
                c = self.left[c]
            reachable.add(c)
        for c in self.left:
            if c not in reachable:
                return False
        return True

    def solve(self):
        self.N = int(raw_input())
        self.groups = raw_input().split(" ")
        self.groups = [ uniq(s) for s in self.groups ]
        if None in self.groups:
            return 0
        #print "DEBUG: groups: %s" % " ".join(self.groups)
    
        self.single = defaultdict(int)
        self.solo = defaultdict(bool)
        self.left = {}
        self.right = {}
        for s in self.groups:
            if len(s) == 1:
                c = s[0]
                if not self.take_single(c):
                    return 0
            else:
                c_left = s[0]
                c_right = s[-1]
                if not self.take_pair(c_left, c_right):
                    return 0
                for c in s[1:-1]:
                    if not self.take_solo(c):
                        return 0
        self.starts = set()
        self.starts.update(( c for c in self.left if c not in self.right ))
        self.starts.update(( c for c in self.single if self.single[c]>0 and c not in self.left and c not in self.right ))
        if not self.check_loops():
            return 0

        start_ordering_possibilities = modfact(len(self.starts))
        possibilities = start_ordering_possibilities
        for c in self.single:
            if self.single[c] > 0:
                possibilities = (possibilities * modfact(self.single[c])) % MOD
        return possibilities

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(T):
        p = Problem()
        x = p.solve()
        print "Case #%d: %d"%(t+1,x)
