import sys, math

f = open(sys.argv[1])
N = int(f.readline())

for i in range(N):
    (r, t) = f.readline().split()
    r = int(r)
    t = int(t)

    D = 4*r*r-4*r+8*t+1
    #print D

    n = math.sqrt(D) - 2 *r  + 1 

    print "Case #" + str(i+1) + ": " + str(int(math.floor(n/4)))