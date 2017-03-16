import sys


def gen(x,agg=0):
    if x:
        if x[0] == '?':
            for i in range(10):
                for p in gen(x[1:], 10*agg + i):
                    yield p
        else:
            for p in gen(x[1:], 10*agg + int(x[0])):
                yield p
    else:
        yield agg

def solve(a,b):
    bestd = int(1e20)
    best = ''
    fmt = '{{:0{l}}} {{:0{l}}}'.format(l=len(a))
    for asc in gen(a):
        for bsc in gen(b):
            if abs(asc-bsc) < bestd:
                bestd = abs(asc-bsc)
                best = fmt.format(asc, bsc)
    return best

if __name__ == '__main__':
    lines = (x.split() for x in sys.stdin.readlines()[1:])
    for t, l in enumerate(lines):
        print('Case #{}: {}'.format(t+1, solve(*l)))

