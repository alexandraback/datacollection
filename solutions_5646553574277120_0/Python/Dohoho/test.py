import math
import itertools
import copy
import sys

debug = False

if debug:
    infile = sys.stdin
    outfile = sys.stdout
else:
    infile = open("C:\\Users\\Aesma\\Desktop\\in.in", "r")
    outfile = open("C:\\Users\\Aesma\\Desktop\\out.txt", "w")


#################################################################################


from itertools import chain, combinations


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def canmake(num, coins, maxx):
    if num < 0:
        return False
    if num == 0:
        return True
    for x in range(len(coins)):
        if maxx[x] > 0:
            maxx2 = maxx[:]
            maxx2[x] -= 1
            if canmake(num - coins[x], coins, maxx2):
                return True
    return False


def solve():
    ii = read()
    maxc = int(ii[0])
    ccoins = int(ii[1])
    V = int(ii[2])
    coins = [int(l) for l in read()]
    for x in powerset(range(1, V + 1)):
        cc = False
        for c in coins:
            if c in x:
                cc = True
        if cc:
            continue
        fug = False
        for i in range(1, V + 1):
            newl = list(x) + coins
            maxx = [maxc for j in range(len(newl))]
            if not canmake(i, newl, maxx):
                fug = True
                break
        if not fug:
            write(len(x))
            return


#################################################################################


def read():
    return infile.readline().split()


def write(s):
    outfile.write(str(s))


testcases = int(read()[0])
for tcase in xrange(1, testcases+1):
    write("Case #%d: " % tcase)
    solve()
    write("\n")