import sys
import itertools

T=int(input())
for case_id in range(1,T+1):
    C,J = input().split()
    def solve():
        def sub(C,J,p):
            cl,jl = list(C),list(J)
            i = 0
            for j in range(len(C)):
                if cl[j] == '?':
                    cl[j] = str(p[i])
                    i+=1
            for j in range(len(C)):
                if jl[j] == '?':
                    jl[j] = str(p[i])
                    i+=1
            return (int(''.join(map(str,cl))),int(''.join(map(str,jl))))
            
        res = (1000000000,0,0)
        for p in itertools.product(range(10), repeat=C.count('?')+J.count('?')):
            c,j = sub(C,J,p)
            res = min(res, (abs(c-j),c,j))
        return str(res[1]).zfill(len(C)) + ' ' + str(res[2]).zfill(len(C))

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
