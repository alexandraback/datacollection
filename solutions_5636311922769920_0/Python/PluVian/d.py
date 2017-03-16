import sys
import decimal

def r():
    return sys.stdin.readline()

def main(k, c, s):
    assert k == s

    ret = []
    interval = decimal.Decimal(k) ** (c - 1)

    for i in range(s):
        ret.append(i * interval + 1)

    return ' '.join([str(x) for x in ret])

t = int(r())

for i in range(t):
    k, c, s = map(int, r().split())
    print('Case #{}: {}'.format(i + 1, main(k, c, s)))
