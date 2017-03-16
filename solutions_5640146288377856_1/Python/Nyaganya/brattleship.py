from sys import stdin

T = int(stdin.readline())

for t in xrange(1,T+1):

    C, R, W = map(int, stdin.readline().split())
    
    x=0
    if (R%W != 0):
       x+=1

    res = (R/W)*C+(W-1) +x

    print "Case #%d: %d" %(t,res)
