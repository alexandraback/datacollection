from itertools import product

def bins(q,w):
    for i in xrange(q):
        yield (('0'*w) +bin(i)[2:])[-w:]

def solve(t):
    print "Case #%d:"%(t+1),
    
    b,m = map(int, raw_input().split())
    
    for graph in product(*[bins(2**(i),b) for i in xrange(b-1,-1,-1)]):
        
        ans = [0]*b
        ans[b-1]=1
        for q in xrange(b-2, -1,-1):
            for w in xrange(q+1,b):
                ans[q]+= ans[w]*int(graph[q][w])
        if ans[0]==m:
            print "POSSIBLE"
            print "\n".join(graph )
            return 

    print "IMPOSSIBLE"
    

def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()