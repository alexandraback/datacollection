import sys
import math

def eva(s):
    s1, s2 = s
    return abs(int(s1)- int(s2))

def deep(s1, s2):
    p1 = s1.find('?')
    ans = None
    if p1 > -1:
        for i in range(10):
            ss1 = s1[:p1] + str(i) + s1[p1+1:] 
            cur = deep(ss1, s2)
            if (ans == None or eva(ans) > eva(cur)):
                ans = cur
    else:
        p2 = s2.find('?')
        if p2 > -1:
            for i in range(10):
                ss2 = s2[:p2] + str(i) + s2[p2+1:] 
                cur = deep(s1, ss2)
                if (ans == None or eva(ans) > eva(cur)):
                    ans = cur
        else:
            return s1, s2
    return ans

            
f = open(sys.argv[1])
T = int(f.readline())
for I in range(T):
    s1, s2 = f.readline()[:-1].split(' ')
    s1, s2 = deep(s1, s2)
    print 'Case #%d: %s %s'%(I+1, s1, s2)

