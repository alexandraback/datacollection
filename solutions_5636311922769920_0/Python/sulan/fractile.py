import math

def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

T = int(input())
for case_num in range(1,T+1):
    K,C,S = map(int,input().split())
    if K > C*S:
        print_result(case_num,'IMPOSSIBLE')
        continue

    p=0
    result = []
    end = False
    while not end:
        q = 0
        for _ in range(C):
            q *= K
            q += p
            p += 1
            if p == K:
                p = 0
                end = True
        result.append(str(q+1))
#    offset = 0
#    result = []
#    while offset < K:
#        result += [str(q+offset+1)]
#        offset += C
    print_result(case_num,' '.join(result))
