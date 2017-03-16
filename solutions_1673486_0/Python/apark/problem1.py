f = open("A-small-attempt0.in", 'r')
allfile = f.read()
lines = allfile.split("\n")
output = []

for i in xrange(1, len(lines)/2):
    first = lines[2*i-1].split(" ")
    p = [float(d) for d in lines[2*i].split(" ")]
    A = int(first[0])
    B = int(first[1])
    minN = A
    minVal = 2+B
    mulProbs = 1
    for i in xrange(len(p)):
        mulProbs *= p[i]
    for n in xrange(A):
        val = 2+2*B-A+2*n-1.0*(1+B)*mulProbs
        mulProbs /= p[A-n-1]
        if val < minVal:
            minVal = val
            minN = n
    output.append(float(minVal))
    
    

f = open("problem1.out", 'w')
for x in xrange(len(output)):
    f.write("Case #" + str(x+1) + ": " + str(output[x]) + "\n")
