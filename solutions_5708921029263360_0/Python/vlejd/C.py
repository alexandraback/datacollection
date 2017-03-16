from itertools import product
from itertools import chain, combinations
from collections import defaultdict as dfd

def powerset(iterable):
  xs = list(iterable)
  return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )  

def solve(t):
    print "Case #%d:"%(t+1),
    
    J,P,S,K = map(int, raw_input().split())
    
    combs = list(product(range(J), range(P), range(S) ))
    if J==P==S==3:
        if K==1:
            print 3
            print "1 1 1"
            print "2 2 2"
            print "3 3 3"
        elif K>=3:
            print 27
            print "\n".join(map(lambda x: ' '.join(map(lambda y:str(y+1),x)), combs))
        elif K==2:
            print 18
            
            top =  "\n".join(map(lambda x: ' '.join(map(lambda y:str(y+1),x)), combs))
            for qq in ["1 1 1","2 2 1", "3 3 1", "1 2 2", "2 3 2","3 1 2", "1 3 3", "2 1 3","3 2 3"]:
                top.replace(qq,"")
                top.replace("\n\n","")
            
            print top
        return
    maxi = 1
    top = [[1,1,1]]
    for c in powerset(combs):
        if (len(c))==0:
            continue
        q = dfd(int)
        w = dfd(int)
        e = dfd(int)
        for cc in c:
            q[(cc[0],cc[1])]+=1
            w[(cc[0],cc[2])]+=1
            e[(cc[1],cc[2])]+=1
        if max(max(q.values()), max(w.values()), max(e.values()))<=K:
            if len(c)>maxi:
                maxi = len(c)
                top=c
    print maxi
    print "\n".join(map(lambda x: ' '.join(map(lambda y:str(y+1),x)), top))
    

def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()