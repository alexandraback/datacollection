T=int(input())
for case_id in range(1,T+1):
    N=int(input())
    weights_n = list(map(float,input().split()))
    weights_k = list(map(float,input().split()))
    weights_n.sort()
    weights_k.sort()

    def war(wn,wk):
        res = 0
        while len(wn) > 0:
            curr = wn.pop()
            for idx in range(len(wk)):
                if curr < wk[idx]:
                    del wk[idx]
                    break
            if len(wn) != len(wk):
                wk.pop(0)
                res += 1
        return res

    def dwar(wn,wk):
        res = 0
        while len(wn) > 0:
            if wn[-1] > wk[-1]:
                res += 1
                wn.pop()
                wk.pop()
            else:
                wn.pop(0)
                wk.pop(-1)
        return res

    score_w = war(weights_n[:], weights_k[:])
    score_dw = dwar(weights_n[:], weights_k[:])
    
    print('Case #%d: %d %d' % (case_id, score_dw, score_w))
    import sys
    print('Case #%d: %d %d' % (case_id, score_dw, score_w), file=sys.stderr)
