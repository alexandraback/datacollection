def runCases(fname,outname):
    case = 0
    with open(fname,'rU') as f:
        for line in f:
            if case == 0: 
                cases = int(line)
                case+=1
                continue
            if case > cases: break
            ans = fashion(line)
            outputCase(ans,outname,case)
            case+=1

def outputCase(ans,outname,case):
    if case == 1: f = open(outname,'w')
    else: f = open(outname,'a')
    f.write("Case #"+str(case)+": "+str(ans)+"\n")
    
def fashion(line):
    clothes = [int(x) for x in line.split(" ")] #J, P, S
    K = clothes[3]
    JP = {}
    JS = {}
    PS = {}
    JPS = {}
    for i in range(clothes[0]):
        for j in range(clothes[1]):
            for k in range(clothes[2]):
                JP[(i+1,j+1)] = 0
                JS[(i+1,k+1)] = 0
                PS[(j+1,k+1)] = 0
                JPS[(i+1,j+1,k+1)] = 0
    while notFull(K,JP,JS,PS,JPS):
        JP,JS,PS,JPS = addOutfit(K,JP,JS,PS,JPS)
    num = 0
    outfits = ""
    for key in JPS.keys():
        if JPS[key] == 1:
            num += 1
            outfits += "\n" + str(key[0]) + " " + str(key[1]) + " " + str(key[2])
    return str(num) + outfits
        
def notFull(K,JP,JS,PS,JPS):
    for key in JPS.keys():
        if JPS[key] == 0:
            if JP[(key[0],key[1])] < K:
                if JS[(key[0],key[2])] < K:
                    if PS[(key[1],key[2])] < K:
                        return True 
    return False
    
def minVal(d):
    val = 0
    inc = None
    for key in d.keys():
        if d[key] > val:
            val = d[key]
            inc = key
    return val
    
def addOutfit(K,JP,JS,PS,JPS):
    for key in JPS.keys():
        if JPS[key] == 0:
            if JP[(key[0],key[1])] < K:
                if JS[(key[0],key[2])] < K:
                    if PS[(key[1],key[2])] < K:
                        JPS[key] = 1
                        JP[(key[0],key[1])] += 1
                        JS[(key[0],key[2])] += 1
                        PS[(key[1],key[2])] += 1
                        return JP,JS,PS,JPS
    assert False,"No match though you looked for one!"
    
runCases("C-large.in","C-large.out")
    