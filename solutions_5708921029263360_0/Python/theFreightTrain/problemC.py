

def solve(J,P,S,K):
    #numberOfOutfits = min(J*P*min(S,K),J*S*min(P,K),S*P*min(J,K))
    jpDict = {}
    jsDict = {}
    psDict = {}
    testN = 0
    outfitStrings = ''
    s=0
    for j in range(J):
        for p in range(P):
            for i in range(S):
                if not (j,p) in jpDict:
                    jpDict[(j,p)] = 0
                if not (j,s) in jsDict:
                    jsDict[(j,s)] = 0
                if not (p,s) in psDict:
                    psDict[(p,s)] = 0
                if max(jpDict[(j,p)],jsDict[(j,s)],psDict[(p,s)]) >= K:
                    continue
                jpDict[(j,p)] += 1
                jsDict[(j,s)] += 1
                psDict[(p,s)] += 1
                outfitStrings += '{} {} {}\n'.format(j+1,p+1,s+1)
                testN += 1
                s += 1
                s = s%S
    #if testN != numberOfOutfits: print('NOOOO')
    #return ''
    return '{}\n{}'.format(testN,outfitStrings[:-1])

for i in range(1,int(input())+1):
    (J,P,S,K) = map(int,input().split(' '))
    #if i in (31,43,61,82,84):
        #print('{},{},{},{}'.format(J,P,S,K))
    print('Case #{}: {}'.format(i,solve(J,P,S,K)))