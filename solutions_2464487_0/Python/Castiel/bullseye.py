import time

stime = time.time()

input = open("bullseye.in" , "r")
output = open("bullseye.out" , "w")
T = int(input.readline())

for j in range(1, T + 1):

    [r, t] = [int(x) for x in input.readline().split(" ")]

    rings = 0

    while t != 0:
        o = r + 2*rings + 1
        i = r + 2*rings
        a = o*o - i*i
        
        if t < a:
            t = 0
        else:
            t = t - a
            rings = rings + 1
    
    print "Case #" + str(j) + ": " + str(rings)
    output.write("Case #" + str(j) + ": " + str(rings) + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
