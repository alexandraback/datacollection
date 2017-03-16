import math

pi = math.pi
infile = open("A-small.txt", "r")
outfile = open("A-out.txt", "w")
testcase = int(infile.readline())
for derp in range(1, testcase+1):
    inline = infile.readline()
    r, t = inline.split()
    r = int(r)
    t = int(t)
    rings = 0
    while t>0:
        needed = ((r+1)**2) - ((r)**2)
        if needed>t:
            break
        else:
            t-=needed
            rings+=1
        r+=2
    output = "Case #" + str(derp) + ": " + str(rings) + "\n"
    outfile.write(output)

infile.close()
outfile.close()
