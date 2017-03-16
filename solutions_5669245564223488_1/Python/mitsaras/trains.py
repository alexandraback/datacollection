#!/usr/bin/python2
from itertools import groupby

m = 1000000007

def factorial(n):
    acc = n
    for i in range(1, n):
        acc *= i
        acc %= m
    return acc

def valid(s):
    seen = set()
    prev = None
    for c in s:
        if ((c in seen) and (c != prev)):
            return False
        else:
            seen.add(c)
            prev = c
    return True

def uniq(s):
    acc = []
    prev = None
    for c in s:
        if (c != prev):
            acc.append(c)
            prev = c
    return "".join(acc)

def merge(combi):
    merged = True
    ncombi = []
    while merged:
        merged = False
        while combi != []:
            s, n = combi.pop()
            added = False
            for ss, nn in combi:
                if s[0] == ss[-1]:
                    merged = True
                    added = True
                    ncombi.append((ss + s,n * nn))
                    combi.remove((ss, nn))
                    break
                elif ss[0] == s[-1]:
                    merged = True
                    added = True
                    ncombi.append((s + ss, n * nn))
                    combi.remove((ss, nn))
                    break
            if not added:
                ncombi.append((s,n))
        combi = ncombi
        ncombi = []
    return combi

def solve(cars):
    cars = [uniq(l) for l in cars]
    single = sorted([s for s in cars if len(s) == 1])
    combi = [(s, 1) for s in cars if len(s) != 1]
    single = [(k, factorial(len(list(g)))) for k, g in groupby(single)]
    cars = merge(single + combi)
    if not valid("".join(s for s, n in cars)):
        return 0
    acc = 1
    for s, n in cars:
        acc = (acc * n) % m
    acc *= factorial(len(cars))
    acc %= m
    return acc

def main():
    t = int(raw_input())
    for i in range(1, t+1):
        n = int(raw_input())
        cars = raw_input().split()
        print("Case #{}: {}".format(i, solve(cars)))

if __name__ == "__main__":
    main()
