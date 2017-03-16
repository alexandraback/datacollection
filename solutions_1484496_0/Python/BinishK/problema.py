from itertools import *
import random
import datetime

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def main(f):
    fi = open(f + '.in')
    fo = open(f + '.out', 'w')
    
    t = int(fi.readline())
#     mx = 1000000000000    
#     t = 10
    
    for i in range(t):
#         start = datetime.datetime.now()
        
        c = fi.readline().split()
        c, s = c[0], c[1:]
        s = [int(j) for j in s]
        s.sort()
        
#         s = [random.randrange(mx)+1 for j in range(500)]
#         s.sort()
        
        su = powerset(s)
        r = {}
        
        
        r_i = None
        n_i = None
        
        j = 0
        for m in su:
            v = sum(m)
            if v in r:
                r_i = r[v]
                n_i = m
                break
                
            r[v] = m 
            j +=1  
        
#         took = datetime.datetime.now() - start
#         print "completed in %d %s sec %s m" % (j, took.seconds, took.microseconds)
        
        if(r_i == None or n_i == None):
            fo.write("Case #%d: Impossible\n" % (i+1))
            print "Case #%d: Impossible" % (i+1)
        else:
            fo.write("Case #%d:\n" % (i+1))
            print "Case #%d:" % (i+1)
            ro = " ".join([str(j) for j in list(r_i)])
            no = " ".join([str(j) for j in list(n_i)])
            fo.write("%s\n%s\n" % (ro, no))
            print "%s\n%s" % (ro, no)
                    
        
if __name__ == "__main__":
    main('C-small-attempt0')