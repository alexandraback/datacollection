from math import ceil
from math import floor
from collections import Counter

f = open('C-small-attempt1.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s[:-1]
    s = s.split()
    N = map(int, s)
    
    J = N[0]
    P = N[1]
    S = N[2]
    K = N[3]
    
    ans = ""
    d1 = {}
    d2 = {}
    d3 = {}
    count = 0
    for i in range(1, J*P*S+1):
        c_J = int(ceil(1.0*i/(P*S)))
        c_S = int(i%S)
        if c_S == 0: 
            c_S = S
        c_P = int(ceil(1.0*(i - (c_J-1) * P * S) / (S)))
        candidate = str(c_J) + " " + str(c_P) + " " + str(c_S)
        #print candidate        
        
        pass_ = True
        if (c_J, c_P) in d1.keys():
            if d1[(c_J, c_P)] >= K:
                pass_ = False
        if (c_J, c_S) in d2.keys():
            if d2[(c_J, c_S)] >= K:
                pass_ = False
        if (c_P, c_S) in d3.keys():
            if d3[(c_P, c_S)] >= K:
                pass_ = False            
    
        if pass_ == False:
            continue

        if (c_J, c_P) in d1.keys():
            d1[(c_J, c_P)] += 1
        else:
            d1[(c_J, c_P)] = 1

        if (c_J, c_S) in d2.keys():
            d2[(c_J, c_S)] += 1
        else:
            d2[(c_J, c_S)] = 1

        if (c_P, c_S) in d3.keys():
            d3[(c_P, c_S)] += 1
        else:
            d3[(c_P, c_S)] = 1
        count += 1

        ans += candidate + "\n"   
     
    if t == 43:
        print "d1", d1, t, K
        print "d2", d2
        print "d3", d3
                     
    outline = "Case #%d: " % (t) + str(count) + "\n"  + ans
    o.write(outline)

o.close()
