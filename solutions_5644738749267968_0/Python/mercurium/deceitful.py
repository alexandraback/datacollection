import string

file_name = "D-small-attempt0.in"

deceitInput = open(file_name, 'r')
data = string.split(deceitInput.read().strip(), '\n')
numCases = int(data[0])

index = 1
for case in range(1,numCases+1):
    n = int(data[index])
    naomi = [float(x) for x in string.split(data[index+1], ' ')]
    naomi.sort()
    ken = [float(x) for x in string.split(data[index+2], ' ')]
    ken.sort()
    index +=3
    i, j = n-1, n-1
    while j >= 0:
        if naomi[i] > ken[j]:
            i,j = i-1, j-1
        else:
            j -=1
    deceitWar = n-1 - i

    i, j = n-1, n-1
    while i >= 0:
        if naomi[i] > ken[j]:
            i = i-1
        else:
            i,j =i-1, j-1
    warScore = j+1
    print "Case #" + str(case) + ":", deceitWar, warScore

