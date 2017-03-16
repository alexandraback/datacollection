from math import *
filename = raw_input("Name of file: ")
f = open(filename, "r")
o = open(filename + ".out", "w")


T = int(f.readline()[:-1])

## Code starts here
for t in range(1, T + 1):
    line = [int(x) for x in f.readline()[:-1].split("/")]
    ones = ((1.0*line[0])/line[1])*2**40
    
    if floor(ones) < ones:
        print "impossible"
        o.write("Case #%d: impossible\n" %(t))
        continue
        
    x = 40 - floor(log(ones)/log(2))
    print int(x)
    o.write("Case #%d: %d\n" %(t, int(x)))
    
## code ends here

o.close()
f.close()
