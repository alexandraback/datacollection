import sys
import time
from itertools import permutations, combinations

in_name = sys.stdin
out_name = sys.stdout

fin = sys.stdin
fout = sys.stdout

class inout:
    IN = fin
    
    @classmethod
    def line(cls, type=str):
        return type(cls.IN.readline().strip())
        
    @classmethod 
    def splitline(cls, type=str):
        return [type(x) for x in cls.IN.readline().split()]


T = inout.line(int)
result = []

t1 = time.time

def solve(N):
    net = []
    d = {}
    for i in range(N):
        line = inout.splitline(int)
        if line[0] > 0:
            net.append(line[1:])
        else:
            net.append([])
    #print net
    yes = False
    for i in range(1, N+1):
        sn = d[i] = set(net[i-1])
        #print i, d[i]
        lsn = 0       
        added = []
        while len(d[i]) != lsn:
            lsn = len(d[i])
            adde = []
            newset = set(d[i])
            for v in d[i]:
                if v in added:
                    continue
                else:
                    added.append(v)
                #print 'v', v
                for el in net[v-1]:
                    #print 'net[v-1]', net[v-1]
                    if el in newset:
                        return 'Yes'
                    else:
                        newset.add(el)
                
            d[i] = newset
            #print sn
    #print d
    return 'No'
for test in range(int(T)):
    #Read input
    N = inout.line(int)
    v = solve(N)    
    result.append("Case #%d: %s\n" % (test+1, v))
    

fout.writelines(result)
fout.close()
fin.close()
t2 = time.time
#print t2 - t1