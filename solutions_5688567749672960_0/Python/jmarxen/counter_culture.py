#counter culture

T = [None, (1,0)]

def rev_num(x):
    sx = str(x)
    sxr = sx[-1:-len(sx)-1:-1]
    sxr = sxr.strip('0')
    if len(sx) != len(sxr):
        return None
    return int(sxr)

def num_C(N, C):
    
    if N > len(C)-1:
        diff = N - len(C) + 2
        C.extend([None]*diff)
    
    if C[N] is None:
        v1 = num_C(N-1,C) #simulate counting down
        rn = rev_num(N)
        if not(rn is None) and rn < N:
            v2 = num_C(rn,C) #reverse number
        else:
            v2 = v1+1
        m = v1
        x = N-1
        if v2 < v1:
            m = v2
            x = rn
            
        C[N] = (m+1,x)
    
    #print "num_C("+str(N)+") is "+str(C[N][0])
    return C[N][0]
    
num_cases = int(raw_input())
cases = []

for case in range(num_cases):
    cases.append(int(raw_input()))
    
m = max(cases)
#print str(m)
for x in range(1,m+1):
    num_C(x,T)

for case in range(len(cases)):
    print "Case #"+str(case+1)+": "+str(T[cases[case]][0])

"""
for x in T:
    print str(x)
"""
    