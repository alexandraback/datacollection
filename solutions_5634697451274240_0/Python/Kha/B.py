import sys

f = sys.stdin #open('C-small-practice.in')
def get_int(): return int(f.readline())
def get_ints(): return [int(s) for s in f.readline().split()]

for t in range(get_int()):
    s = f.readline()
    bit = '+'
    res = 0
    for p in reversed(s[:-1]):
        if p != bit:
            res += 1
            bit = '-' if bit == '+' else '+'
    print('Case #%d: %d' % (t+1, res))
