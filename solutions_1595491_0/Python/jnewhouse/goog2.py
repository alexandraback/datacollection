L = [[x/121,(x/11)%11,x%11] for x in range(11**3)]
unsurprising = [x for x in L if max(x)-min(x) < 2]
surprising = [x for x in L if max(x)-min(x)==2]
USTable = [0,0]+[[max(z) for z in L if sum(z)==y and max(z)-min(z)<2][0] for y in range(2,29)]
STable = [0,0]+[[max(z) for z in L if sum(z)==y and max(z)-min(z)==2][0] for y in range(2,29)]


T = int(raw_input())
for t in range(T):
    print "Case #"+str(t+1)+":",
    total=0
    R = [int(x) for x in raw_input().split()]
    
    N, S, p = R[:3]
    R = R[3:]
    extra =sum([(r+2)/3>=p for r in R if r in [0,1,29,30]])
    R = [r for r in R if 1<r and r < 29]
    less = 0
    greater = 0
    straddling = 0
    for r in R:
        if USTable[r]>=p:
            greater+=1
        elif STable[r]<p:
            less+=1
        else:
            straddling+=1
    print extra + greater +min(S,straddling)
