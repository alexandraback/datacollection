import math

global E
global R
global N
global values

def calc(current, task):
    if current>E:
        current = E
    if task==N-1:
        return current*values[task]
    ans = 0
    i=0
    while i<=current:
        ans = max(ans, i*values[task]+calc(current-i+R,task+1))
        i+=1
    return ans

infile = open("B-small.txt", "r")
outfile = open("B-out.txt", "w")
testcase = int(infile.readline())
for derp in range(1, testcase+1):
    E, R, N = infile.readline().split()
    E, R, N = int(E), int(R), int(N)
    values = infile.readline().split()
    values = [int(i) for i in values]
    gain = calc(E, 0)
    output = "Case #" + str(derp) + ": " + str(gain) + '\n'
    outfile.write(output)
    
infile.close()
outfile.close()
