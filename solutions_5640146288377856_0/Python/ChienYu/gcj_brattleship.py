from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')
import pickle

base_cases = {(0,0,0) : 0}

def base_case(L, a, b):
    if L <= 0 or a < 0 or b < 0: return 0
    if a == 0 or b == 0: return L
    return base_cases[(L, a, b)]
    #return min(min(max(base_case(L, c, b), base_case(L-c-1, a-c-1, b) + c) for c in range(a)), min(max(base_case(L, a, c), base_case(L-c-1, a, b-c-1) + c) for c in range(b))) + 1

def pre_compute():
    for L in range(1, 20):
        for a in range(L+1):
            for b in range(L+1):
                if a == 0 or b == 0:
                    base_cases[(L, a, b)] = L
                else:
                    base_cases[(L, a, b)] = min(min(max(base_case(L, c, b), base_case(L-c-1, a-c-1, min(L-c-1, b)) + c) for c in range(a)), min(max(base_case(L, a, c), base_case(L-c-1, min(L-c-1, a), b-c-1) + c) for c in range(b))) + 1
    pickle.dump(base_cases, open('gcj_1C_A.pickle', 'w'))

def each_case(R, C, W):
    b = pickle.load(open('gcj_1C_A.pickle'))
    return (C/W)*R + max(b[(W-1, W-1, C%W)], b[(W-1, W-1, W-1)] - R)

#pre_compute()
T = int(stdin.readline())
for t in xrange(1,T+1):
    R, C, W = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, each_case(R, C, W))
