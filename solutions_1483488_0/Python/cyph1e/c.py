T = int(raw_input())
for t in range(T):
    A, B = map(int, raw_input().split())
    cnt = 0
    s = set()
    for i in range(A, B + 1):
        n = str(i)
        for j in range(1, len(n)):
            m = n[j:] + n[:j]
            if n[j] == '0' or n == m: continue
            k = int(m)
            if A <= k <= B:
                h = n + m if n < m else m + n
                s.add(h)
    
    #print s
    #if t == 1: break
    print "Case #{0}: {1}".format(t + 1, len(s)) 

