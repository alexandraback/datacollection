
import sys
import random

inp = "C.in"
out = "C.out"

INPUT = open(inp, "r")
OUTPUT = open(out, "w")

primes = []

for i in xrange(2, 100000):
    j = 2
    f = True
    while j*j <= i:
        if i % j == 0:
            f = False
            break
        j += 1
    if f:
        primes.append(i)


T = int(INPUT.readline())
N, J = map(int, INPUT.readline().split())


def get_div(val):
    for p in primes:
        if p >= val:
            return None
        if val % p == 0:
            return p
    return None


def check(s):
    res = []
    for base in xrange(2, 11):
        val = 0
        deg = 1
        for c in reversed(s):
            if c == "1":
                val += deg
            deg *= base
        div = get_div(val)
        if div is None:
            return None
        res.append(str(div))
    return res


ans = dict()

print >>OUTPUT, "Case #1:"

while len(ans) < J:
    s = ""
    for i in xrange(N - 2):
        s += str(random.randint(0, 1))
    s = "1" + s + "1"
    if s in ans:
        continue
    res = check(s)
    if res is not None:
        ans[s] = res
        print >>OUTPUT, s, " ".join(ans[s])
