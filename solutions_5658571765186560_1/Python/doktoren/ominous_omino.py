import sys

def solve(x, r, c):
    if (r*c) % x != 0:
        #print "Not divisible"
        return False
    if x <= 2:
        #print "Trivial"
        return True
    if x >= 7:
        #print "A hole in the piece"
        return False
    # x in [3,4,5,6]
    if (x+1)/2 > min(r, c):
        #print "L shaped piece cannot fit"
        return False
    if x == 3:
        #print "x==3"
        return True
    # x in [4,5,6]
    n = r*c/x
    if n == 1:
        #print "Make one non-rectangular piece"
        return False
    if min(r, c) == 2:
        #print "x is 4. s shaped piece"
        return False
    if x == 4:
        #print "x==4"
        return True
    # x in [5,6]
    if x == 5:
        if n == 3:
            # w
            return False
        return True
    # x is 6
    if min(r, c) == 3:
        # w
        return False
    return True

with open(sys.argv[1], 'r') as f:
    t = int(f.readline().strip())
    for n in range(1, t+1):
        x, r, c= (int(s) for s in f.readline().strip().split(" "))
        print "Case #{}: {}".format(n, "GABRIEL" if solve(x, r, c) else "RICHARD")
