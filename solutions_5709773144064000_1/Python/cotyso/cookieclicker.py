from __future__ import print_function

outFile = open("cookieclicker.out", "w")

#lines = list(open("cookieclicker.in"))
#lines = list(open("B-small-attempt0.in"))
lines = list(open("B-large.in"))
testCount = int(lines.pop(0))

for test in range(1, testCount+1):
    C, F, X = [float(x) for x in str.split(lines.pop(0))]

    time = 0.0
    crtSpeed = 2.0
    
    if X / crtSpeed < C / crtSpeed:
        time = X / crtSpeed
    else:
        time = C / crtSpeed
        #print(time)
        while (X-C) / crtSpeed > X / (crtSpeed + F):
            crtSpeed += F
            time += C / crtSpeed
            #print(time, crtSpeed)
        time += (X-C) / crtSpeed
    
    print("Case #{}: {:.7f}".format(test, time))
    outFile.write("Case #{}: {:.7f}\n".format(test, time))

outFile.close()
