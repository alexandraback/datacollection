


T = int(raw_input())

for t in range(T):
    
    A, B = map(int, raw_input().split())
    
    
    n_pairs = 0
    
    for i in range(A, B+1):
        n = str(i)
        
        pairs = []
        for c in range(1, len(n)):
            m = n[c:]+n[:c]
            j = int(m)
            if m[0] != "0" and i < j <= B and (i, j) not in pairs:
                n_pairs += 1
                pairs.append((i, j))
    
    print "Case #"+str(t+1)+":", n_pairs



