import sys
T=int(input())
for case_id in range(1,T+1):
    K,C,S = map(int,input().split())

    def solve(is_first, stack, covered, res):
        if len(stack) == C:
            n = 0
            while len(stack)>0:
                n *= K
                n += stack.pop(-1)
            res.append(n)
            return

        def get_next():
            cov = 0 if len(covered) == 0 else min(K-1,covered[-1]+1)
            covered.append(cov)
            return cov

        if is_first:
            while True:
                nex = get_next()
                solve(False, stack + [nex], covered, res)
                if covered[-1] == K-1:
                    return
        else:
            solve(False, stack + [get_next()], covered, res)
            
    covered,res = [],[]
    solve(True, [], covered, res)
    if len(res) > S:
        ans = 'IMPOSSIBLE'
    else:
        ans = ' '.join(str(n+1) for n in res)
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
