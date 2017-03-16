import sys

inputFile = sys.argv[1]
outputFile = sys.argv[1][:-3] + ".out"

#s - num of suprise left
#p - goal
#return 1,1 best is >= p, used 1 surprise
def cal(score,s,p):
    avg = score//3
    print("avg",avg)
    if avg >= p: return (1,0) 
    
    if score%3 == 1:
        if avg + 1 >= p: return (1,0)
    elif score%3 == 0 and score > 0:
        if s>0 and avg + 1 >= p: return (1,1)
    elif score%3 == 2:
        if avg + 1 >= p: return (1,0)
        if s>0 and avg + 2 >= p: return (1,1)
    
    return (0,0)

result = []
for i,case in enumerate(open(inputFile)):
    if i == 0: continue #drop first line
    
    case = list(map(int, case.strip().split(' ')))
    n,s,p = case[:3]
    scores = case[3:]
    
    print(case)
    print(n)
    print(s)
    print(p)
    print (scores)
    
    total = 0
    for score in scores:
        ok, usedS = cal(score, s, p)
        total += ok
        s -= usedS
        print(ok,usedS,s)
    
    ans = "Case #%d: %s" % (i, total)
    result.append(ans)
    print(ans)

f = open(outputFile,'w')
f.write('\n'.join(result))