def b(oldM, newM, kM):
    count = 0
    for o in oldM:
        for n in newM:
            if (n & o) in kM:
                count +=1
    return count






FILENAME = "B-small-attempt0"
f = open(FILENAME + '.in', 'r')
T = int(f.readline())
output = []

for i in range(T):
    temp = f.readline().split(' ')
    A = int(temp[0])
    B = int(temp[1])
    K = int(temp[2])
    """oldM = []
    for j in range(A):        
        oldM.append(int(bin(j)[2:]))

    newM = []
    for j in range(B):
        newM.append(int(bin(j)[2:]))
        
    kM = []
    for j in range(K):
        kM.append(int(bin(j)[2:]))
    """
    oldM = range(A)
    newM = range(B)
    kM = range(K)
    output.append("Case #"+str(i+1)+": " + str(b(oldM, newM, kM)))
    #print output[i]


f.close()
output = '\n'.join(e for e in output)
f = open(FILENAME + '.out', 'w')
f.write(output)
f.close()
