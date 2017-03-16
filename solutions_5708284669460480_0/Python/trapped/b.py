from collections import defaultdict
T = int(raw_input())

def expected(m, i, target, words, memo):
    L = len(target)
    if m < L - i: return 0.
    if (m,i) in memo: return memo[(m,i)]
    numw = sum(words.values())
    if i == L-1:
        p = words[target[L-1]]*1.0/numw
        ans = p * (1 + expected(m-1, 0, target, words, memo)) + (1-p)*expected(m-1, 0, target, words, memo)  ## lps in first part
        memo[(m,i)] = ans
        return ans
    p = words[target[i]]*1.0/numw
    ans = p * (expected(m-1, i+1, target, words, memo)) + (1-p)*expected(m-1, 0, target, words, memo)
    memo[(m,i)] = ans
    return ans

for t in range(1,T+1):
    K,L,S = map(int, raw_input().split())
    chars = raw_input().strip()
    words = defaultdict(int)
    for w in chars:
        words[w] += 1
    numw = sum(words.values())
    target = raw_input().strip()
    ispossible = True
    
    for w in target:
        if w not in words:
            ispossible = False
            break
    memo = {}
    if not ispossible: ex = 0.
    else: ex = expected(S, 0, target, words, memo)
    print "Case #%d: %.7f"%(t, S//L - ex)
