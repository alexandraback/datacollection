#!/usr/bin/python3

import sys

modulo = 1000000007
t = int(sys.stdin.readline())

def short(x):
    s = '#'
    for c in ''.join(x):
        if c != s[-1]:
            s += c
    return s[1:]

def is_valid(s):
    return len(s) == len(set(s))

def factorial(x):
    if x == 0:
        return 1
    return x*factorial(x-1)

def razdeli(trains, c):
    beg = [] # zacetek je razlicen
    end = []
    vse = []
    sreda = []
    nic = []
    for t in trains:
        if c not in t:
            nic.append(t)
        elif len(set(t)) == 1:
            vse.append(t)
        elif (t[0] != c) and (t[-1] != c):
            sreda.append(t)
        elif t[0] != c:
            beg.append(t)
        else:
            end.append(t)
    return beg, end, vse, sreda, nic

def solve(trains):
    trains = [short(x) for x in trains]
    # print(trains)
    ans = 1
    for t in trains:
        if not is_valid(t):
            return 0
    
    # print(trains)
    for letter in 'abcdefghijklmnopqrstuvwxyz':
        beg, end, vse, sreda, nic = razdeli(trains, letter)
        
        """print('letter:', letter)
        print(beg)
        print(end)
        print(vse)
        print(sreda)
        print(nic)
        print('*************************************')
        """
        if len(beg) + len(end) + len(vse) + len(sreda) == 0: continue # not used
        if len(sreda) > 1:
            return 0 # ne gre
        if len(sreda) == 1:
            if len(beg + end + vse) > 0:
                return 0
            pass # ok, nothing to do
        else:
            # sreda is empty
            if len(beg) > 1:
                return 0 # ne gre
            if len(end) > 1:
                return 0 # ne gre
            ans *= factorial(len(vse))
            nov = (beg[0] if len(beg) > 0 else '') + ''.join(vse) + (end[0] if len(end) > 0 else '')
            nov = short(nov)
            if not is_valid(nov):
                return 0
            trains = nic + [nov]
            
        # print(trains)
        # print(ans)
    
    return ans * factorial(len(trains))

for test_case_number in range(1, t+1):
    n = map(int, sys.stdin.readline())
    trains = sys.stdin.readline().split()
    print('Case #%d: %d' % (test_case_number, solve(trains) % modulo))
