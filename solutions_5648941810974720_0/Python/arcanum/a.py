from math import *

def rl(l): return range(len(l))



snums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "QQQ"]


def go(l, i, d):

    #if [all(d[e] == 0 for e in d)]:

    if i < 0:
        #print(d)

        end = True
        for e in d:
            if d[e] != 0:
                end = False
        if end:
            #print("SUCCESS")
            #print(d)
            return l

        else:
            return None

    #newd = {e:d[e] for e in d}

    strnum = snums[i]
    dsn = dict()
    for c in strnum:
        if c in dsn:
            dsn[c] += 1
        else:
            dsn[c] = 1

    maxtimes = 2000+1
    good = False
    notgood = False
    
    for numchar in dsn:
        if numchar in d:
            good = True
            maxtimes = min(maxtimes, int(d[numchar]/dsn[numchar])) ## / dsn[numchar])) # no dsn.get(c,0)
            #if i == 2: print(d.get(numchar, 0)/dsn[numchar])
        elif (not numchar in d) and i < 10:
            notgood = True

    if not good or notgood:
        maxtimes = 0
    

    ret = None

    if i >9: maxtimes=0

    for rep in range(maxtimes+1):
        lcopy = [e for e in l]
        lcopy[i] = rep  # which why i-1 giving 10?

        dcopy = {e:d[e] for e in d}
        for k in dsn:
            if k in dcopy: # deal with J case
                #print("subtracting", i, k, rep, maxtimes, dcopy)
                dcopy[k] -= dsn.get(k,0)*rep
        
        g = go(lcopy, i-1, dcopy)
        if g:
            ret = g # don't call twice!!

    return ret
        
        


f = open("a.out", mode='w')

T = int(input())

for nt in range(1, T+1):
    S = input()


    d = dict()
    for c in S:
        if c in d:
            d[c] += 1
        else:
            d[c] = 1

    l = [0 for i in range(10+1)]
    ansl = go(l, 10, d)

    #print(ansl)
    ans = "".join(str(i)*ansl[i] for i in rl(ansl))
        

    
    towrite = "Case #"+str(nt)+": "+str(ans)+'\n'
    f.write(towrite)
    print(towrite, end="")
    
f.close()

'''
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
'''
