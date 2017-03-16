import sys

def read_input():
    s = sys.stdin.read()
    data = filter(len, s.replace("\n", " ").split(" "))
    data = map(int, data)
    T = data.pop(0)
    cases = []
    for _ in xrange(T):
        [a, b, k] = data[0:3]
        if a > b: a, b = b, a
        cases.append((a, b, k))
        data = data[3:]
    return cases

def smaller(a, b, k):
    if a&b < k:
        return 1
    else:
        return 0

def solve(c):
    a, b, k = c
    k1 = min(a, b, k)
    combis = k1*b + (a-k1)*k1
    combis += sum([int(smaller(ax, bx, k)) for ax in xrange(k, a) for bx in xrange(k, b)])
    return combis

if __name__ == "__main__":
    cases = read_input()
    idx = 1
    for c in cases:
        print "Case #%d: %s" % (idx, solve(c))
        idx += 1
