import sys

def solve(x, r, c):
    if x == 1:
        #print "Trivial"
        return True
    if (r*c) % x != 0:
        #print "Not divisible"
        return False
    if x == 2:
        #print "1x2 shaped"
        return True
    if (x+1)/2 > min(r, c):
        #print "L shaped piece cannot fit"
        return False
    if x == 3:
        #print "x==3"
        return True
    n = r*c/x
    if n == 1:
        #print "Make one non-rectangular piece"
        return False
    if x % 2 == 0 and min(r, c) == 2:
        #print "s shaped piece"
        return False
    #print "x==4"
    return True

with open(sys.argv[1], 'r') as f:
    t = int(f.readline().strip())
    for n in range(1, t+1):
        x, r, c= (int(s) for s in f.readline().strip().split(" "))
        print "Case #{}: {}".format(n, "GABRIEL" if solve(x, r, c) else "RICHARD")
