import numpy as np

def GCD(x,y):
    if(y == 0):
        return x
    else:
        return GCD(y,x%y)

def factorize(x,y):
    gcd = GCD(x,y)
    return x/gcd,y/gcd

def isPow2(num):
    return num != 0 and ((num & (num - 1)) == 0)


infile = open("input.in")
lines = infile.read().split('\n')
numCases = int(lines[0])
lines = lines[1:]
print numCases

infile.close()
outputFile = open('output.out','w')

for i in range(len(lines)):
    count = 0
    fraction = map(int,lines[i].split('/'))
    fraction[0],fraction[1] = factorize(fraction[0],fraction[1])
    print fraction
    if (not isPow2(fraction[1])):
        outputFile.write("Case #" + str(i+1) + ": impossible\n")
        print ("Case #" + str(i+1) + ": impossible\n")
    else:
        while(fraction[0]/fraction[1] < 1):
            fraction[0] *= 2
            count += 1
        outputFile.write("Case #" + str(i+1) + ": " + str(count) + "\n")
        print ("Case #" + str(i+1) + ": " + str(count) + "\n")
    

outputFile.close()
