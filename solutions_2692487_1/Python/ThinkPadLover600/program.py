#!/usr/bin/env python
import fileinput

def getlines():
    inp = fileinput.input()
    for line in inp:
        yield map(int, line.rstrip().split())

getline = getlines()
cases = getline.next()[0]


def solve(a, motes):
    if len(motes) == 0:
        return 0
    elif a == 1:
        return len(motes)
    elif min(motes) < a:
        for mote in filter(lambda x: x < a, motes):
            motes.remove(mote)
            a += mote
        return solve(a, motes)
    else:
        rm = solve(a, motes[1:]) + 1
        steps = 0
        while a <= motes[0]:
            a += a - 1
            steps += 1
        add = solve(a, motes) + steps
        return min(rm, add)



for case in range(cases):
    a, n = getline.next()
    steps = solve(a, sorted(getline.next()))
    print("Case #%d: %s" % (case + 1, str(steps)))
