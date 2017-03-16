#!/usr/bin/env python

from __future__ import print_function

from heapq import *

class Tribe(object):
    def __init__(self, d, n, w, e, s, delta_d, delta_p, delta_s):
        self.delta_d = delta_d
        self.delta_p = delta_p
        self.delta_s = delta_s
        self.nextAttack = d
        self.attacksLeft = n
        self.strength = s
        self.w = w
        self.e = e

    def attack(self):
        assert self.attacksLeft > 0
        retVal = (self.w, self.e, self.strength)
        self.e += self.delta_p
        self.w += self.delta_p
        self.strength += self.delta_s
        self.attacksLeft -= 1
        if self.attacksLeft > 0:
            self.nextAttack += self.delta_d
        else:
            self.nextAttack = None
        return retVal

MID = 250
class World(object):
    def __init__(self, tribes):
        self.tribes = tribes
        self.wall = [0] * (MID * 2)
        self.queue = []
        for (i, t) in enumerate(self.tribes):
            heappush(self.queue, (t.nextAttack, i))

    def simulateDay(self):
        curDay = self.queue[0][0]
        dayAttacks = []
        numSuccessful = 0
        while self.queue and self.queue[0][0] == curDay:
            day, tribe = heappop(self.queue)
            #print('Tribe', tribe, 'at day', day)
            attack = self.tribes[tribe].attack()
            if self.tribes[tribe].nextAttack:
                heappush(self.queue, (self.tribes[tribe].nextAttack, tribe))
            if self.attackSuccessful(attack):
                numSuccessful += 1
            dayAttacks.append(attack)
        for a in dayAttacks:
            self.buildWall(a)
        return numSuccessful

    def solve(self):
        numTotal = 0
        while self.queue:
            numTotal += self.simulateDay()
        return numTotal

    def attackSuccessful(self, (w, e, s)):
        #print('Checking attack', (w, e, s))
        for x in xrange(w + MID, e + MID):
            #print('Checking wall at', x, ':', self.wall[x])
            if self.wall[x] < s:
                return True
        return False

    def buildWall(self, (w, e, s)):
        for x in xrange(w + MID, e + MID):
            self.wall[x] = max(self.wall[x], s)

def readTribes(N):
    tribes = []
    for i in xrange(N):
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si = (
                map(int, raw_input().split()))
        tribes.append(Tribe(di, ni, wi, ei, si, delta_di, delta_pi, delta_si))
    return tribes

def readSolveCase():
    N = int(raw_input())
    tribes = readTribes(N)
    world = World(tribes)
    return world.solve()

def main():
    T = int(raw_input())
    for casenum in xrange(1, T+1):
        print('Case #', casenum, ': ', readSolveCase(), sep='')

if __name__ == '__main__':
    main()
