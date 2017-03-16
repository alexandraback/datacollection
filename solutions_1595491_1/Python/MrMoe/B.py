




T = int(raw_input())

for t in range(T):
    inp = map(int, raw_input().split())
    N = inp[0]
    S = inp[1]
    p = inp[2]
    scores = inp[3:]
    if N != len(scores):
        raise Exception
    
    if p > 1:
        number = 0
        s_rem = S
    
        nsup = p+2*(p-1)
        sup = p+2*(p-2)
        for score in scores:
            if score >= nsup:
                number += 1
            elif score >= sup and s_rem:
                number += 1
                s_rem -= 1
    elif p == 1:
        number = 0
        
        for score in scores:
            if score > 0:
                number += 1
    else:
        number = N
        
    print "Case #"+str(t+1)+":", number


