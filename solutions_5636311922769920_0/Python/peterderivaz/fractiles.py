def go(K,C,S):
    # We can test C base K digits with each person
    if C*S < K:
        return "IMPOSSIBLE"
    A = []
    digits_tested = 0
    while digits_tested<K:
        x = 0
        for i in range(C):
            x = x*K + (digits_tested%K)
            digits_tested += 1
        A.append(str(x+1))
    return ' '.join(A)

for t in range(input()):
    K,C,S = map(int,raw_input().split())
    print "Case #{}: {}".format(1+t,go(K,C,S))
    
    
