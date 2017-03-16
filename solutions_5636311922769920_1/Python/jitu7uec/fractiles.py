def effpow(a, n):
    ret = 1
    while n:
        if n & 1:
            ret = ret * a
        a = a * a
        n >>= 1
    return ret

T = input()

for x in range(T):
    
    K,C,S = [int(i) for i in raw_input().split()]

    if C == 1:
        if S < K:
            ans = "IMPOSSIBLE"
        else:
            ans = " ".join(str(c) for c in range(1, K+1))

    else: # C > 1
        if S < (K+1)/2:
            ans = "IMPOSSIBLE"
        else:
            ans = " ".join(str(i * effpow(K, C-1) + K - i)  for i in range((K+1)/2))

    print "Case #%d: %s" % (x+1, ans)
       
