import sys

cases = int(input())
for caseno in range(1, cases + 1):
    a, b = map(int, sys.stdin.readline().split())
    correctprob = list(map(float, sys.stdin.readline().split()))
    
    #keep typing
    probkeeptype_r = 1.0
    for prob in correctprob:
        probkeeptype_r *= prob
        
    rt = (b - a + 1)
    wt = rt + b + 1
    exp = probkeeptype_r * rt + (1 - probkeeptype_r) * wt
    
    #press enter
    exp2 = 1 + b + 1
    if exp2 < exp:
        exp = exp2
    
    #press backspace
    for i in range(1, a):
        #pressing backspace i times shot
        #ith char is right or wrong, smaller than i is right, don't care others
        probok = 1.0
        for k in range(a - i):
            probok *= correctprob[k]
            
        rt = i + (b - a + i + 1)
        wt = rt + b + 1
        exptmp = probok * rt + (1 - probok) * wt
        
        if exptmp < exp:
            exp = exptmp
        
    print("Case #{0}: {1}".format(caseno, exp))
        
    
     
        
        