import math

def bsearch (lower, larger, base, t):
    mid = (lower+larger)//2
    total = mid*base+ (mid*(mid-1))*2
    if total==t:
        return mid
    if total>t:
        if total-(base+4*(mid-1)) < t:
            return mid-1
        else:
            return bsearch(lower, mid-1, base, t)
    elif total<t:
        if total+(base+4*(mid-1)) > t:
            return mid
        else:
            return bsearch(mid+1, larger, base, t)
pi = math.pi
infile = open("A-large.txt", "r")
outfile = open("A-out.txt", "w")
testcase = int(infile.readline())
for derp in range(1, testcase+1):
    inline = infile.readline()
    r, t = inline.split()
    r = int(r)
    t = int(t)
    base = 2*r+1
    rings = bsearch(1, 10**15, base, t)
    output = "Case #" + str(derp) + ": " + str(rings) + "\n"
    outfile.write(output)

infile.close()
outfile.close()
