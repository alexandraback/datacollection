import math
    
def getMaximun(score):
    score = int(score)
    scores=list()
    scores.append(math.ceil(score/3.0))
    scores.append(math.ceil((score-scores[0])/2.0))
    scores.append(score-scores[0]-scores[1])
    
    if score==0 or score==1 or score==30 or score==29:
        return {"max":scores[0],"sur":False}    
    if( scores[0]==scores[1]):
        return {"max":scores[0]+1,"sur":True}
    else:
        return {"max":scores[0],"sur":False}

f = open('B-small-attempt0.in', 'r').read().splitlines()
n = int(f[0])
for i in range(1, n+1):
    data = f[i].split()
    n = int(data[0])
    s = int(data[1])
    p = int(data[2])
    
    normales=0
    surprisings=0
    
    for ti in data[3:]:
        tripletas = getMaximun(ti)
        if not tripletas["sur"] and tripletas["max"] >= p:
            normales+=1
        elif tripletas["sur"] and tripletas["max"]-1 >= p:
            normales+=1
        elif tripletas["sur"] and tripletas["max"] >= p and s>0:
            surprisings+=1
            s-=1

    print "Case #%d: %d" % ( i, normales+surprisings )
