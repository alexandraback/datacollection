# python helper to preprocess the input -- the output is pasted into the html5 page
from sys import stdin
T = int(stdin.readline())
for t in range(1,T+1):
    H, W, D = [ int(x) for x in stdin.readline().split() ]
    mapa = [ stdin.readline() for h in range(H) ]
    for h in range(H):
        for w in range(W):
            if mapa[h][w]=='X': jah,jaw = h,w
    print "        window.testCases.push(new TestCase(%d,%d,%d,%d,%d,%d));" % (t,2*W,2*H,2*jaw+1,2*jah+1,2*D)

