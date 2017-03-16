from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')
import pickle

def reverse10(n):
    if n % 10 == 0:
        return None
    a = 0
    while n > 0:
        n, a = n/10, (a*10 + n%10)
    return a

def pre_compute(N = 1000000):
    count = {0:0}
    for n in xrange(1, N+1):
        r = reverse10(n)
        if r in count:
            count[n] = min(count[n-1], count[r]) + 1
        else:
            count[n] = count[n-1] + 1
    pickle.dump(count, open('gcj_1B_2.pickle', 'w'))

#pre_compute()
count = pickle.load(open('gcj_1B_2.pickle'))
T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    print 'Case #{}: {}'.format(t, count[N])
