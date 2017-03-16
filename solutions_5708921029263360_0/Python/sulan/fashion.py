import math
import sys
import collections

def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

def gen(J,P,S,K,w):
    r=[]
    j = 0
    s = 1
    seen = set()
    for a in range(1,J+1):
        for b in range(1,P+1):
            if K>=S and j >= K or (b,s) in seen:
                return r
            j += 1
            tmp2 = w+1 if K>=S else K+1
            for i in range(1,tmp2):
                if K < S:
                    tmp = s
                else:
                    tmp = i
                s += 1
                if s > S:
                    s = 1
                r.append([a,b,tmp])
                seen.add((b,tmp))
    return r


T = int(input())
for case_num in range(1,T+1):
    J,P,S,K = map(int,input().split())
    u = min(S,K)
    r = gen(J,P,S,K,u)
    print_result(case_num,str(len(r))+'\n'+'\n'.join([' '.join([str(b) for b in a]) for a in r]))
