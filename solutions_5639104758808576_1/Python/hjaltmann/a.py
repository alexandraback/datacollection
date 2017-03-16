import sys

def sol(seq):
    acc = 0
    needed = 0
    for i,n in enumerate(seq):
        if acc < i:
            extra = i - acc
            needed += extra
            acc += extra
        acc += n
    return needed

for i, line in enumerate(sys.stdin.read().splitlines()[1:]):
    seq = map(int,line.split()[1])
    print('Case #%s:' % (i+1), sol(seq))
