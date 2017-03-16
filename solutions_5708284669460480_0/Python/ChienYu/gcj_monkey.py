from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')

def each_case(K, L, S, keyboard, target):
    for t in target:
        if t not in keyboard: return 0

    kk = {}
    for k in keyboard:
        if k in kk: kk[k] += 1
        else: kk[k] = 1

    pp = 1
    for t in target:
        pp *= kk[t]
    E = float((S-L+1) * pp) / float(K ** L)

    for t in xrange(1, L):
        if target[t:] == target[:-t]:
            max_len = (S-L) / t + 1
    else:
        max_len = S / L

    return max_len - E

T = int(stdin.readline())
for t in xrange(1,T+1):
    K, L, S = map(int, stdin.readline().split())
    keyboard = stdin.readline()[:K]
    target = stdin.readline()[:L]
    print 'Case #{}: {}'.format(t, each_case(K, L, S, keyboard, target))
