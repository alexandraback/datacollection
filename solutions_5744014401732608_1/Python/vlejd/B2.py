from itertools import product

def bins(q,w):
    return (('0'*w) +bin(q)[2:])[-w:]

def solve(t):
    print "Case #%d:"%(t+1),
    
    b,m = map(int, raw_input().split())
    
    if 2**(b-2)< m:
        print "IMPOSSIBLE"
        return
    
    print "POSSIBLE"
    ans =  bins(m-1,b)
    if not m%2:
        ans=ans+'1'
    else:
        ans = ans+'0'
    print ans[1:]
    print '\n'.join([bins((2**(i))-1,b) for i in xrange(b-2,-1,-1)])
    

def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()