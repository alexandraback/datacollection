digits=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def makeMap(s):
    freq={}
    for i in s:
        try: freq[i]+=1
        except: freq[i]=1
    return freq

def check(s, freq):
    s = makeMap(s)
    for k in s.keys():
        if k not in freq: return False
        if s[k]>freq[k]: return False
    return True

def re(freq, s):
    s = makeMap(s)
    for k in s.keys():
        freq[k]=freq[k]-s[k]

def solve(s):
    result=[]
    freq={}
    for i in s:
        try: freq[i]+=1
        except: freq[i]=1
    ## Zeros
    if 'Z' in freq:
        while freq['Z']>0:
            if not check(digits[0], freq): return False
            re(freq, digits[0])
            result.append(0)
    ## TWOS
    if 'W' in freq:
        while freq['W']>0:
            if not check(digits[2], freq): return False
            re(freq, digits[2])
            result.append(2)
    ## SIXES
    if 'X' in freq:
        while freq['X']>0:
            if not check(digits[6], freq): return False
            re(freq, digits[6])
            result.append(6)
    ## EIGHTS
    if 'G' in freq:
        while freq['G']>0:
            if not check(digits[8], freq): return False
            re(freq, digits[8])
            result.append(8)
    ## FOURS
    if 'U' in freq:
        while freq['U']>0:
            if not check(digits[4], freq): return False
            re(freq, digits[4])
            result.append(4)
    ## SEVENS
    if 'S' in freq:
        while freq['S']>0:
            if not check(digits[7], freq): return False
            re(freq, digits[7])   
            result.append(7)
    ## FIVEs
    if 'V' in freq:
        while freq['V']>0:
            if not check(digits[5], freq): return False
            re(freq, digits[5])  
            result.append(5)
    ## THREE
    if 'T' in freq:
        while freq['T']>0:
            if not check(digits[3], freq): return False
            re(freq, digits[3])  
            result.append(3)    
    ## ONME
    if 'O' in freq:
        while freq['O']>0:
            if not check(digits[1], freq): return False
            re(freq, digits[1])  
            result.append(1)
    ## NINE
    if 'E' in freq:
        while freq['E']>0:
            if not check(digits[9], freq): return False
            re(freq, digits[9])  
            result.append(9)
    for v in freq.values():
        if v>0: print "WTF"
    return result

import sys
f=open(sys.argv[1], "r")
F=open(sys.argv[1]+".out", "w")
N = int(f.readline())
for i in range(N):
    result = solve(f.readline().rstrip())
    result.sort()
    result = map(str, result)
    result =  "".join(result)
    F.write("Case #%d: %s\n" % (i+1, result))
F.close()
