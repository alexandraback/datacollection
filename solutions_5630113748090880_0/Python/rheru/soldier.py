import math

f=open('B-small-attempt1.in', 'r')
g=open('outputsmall.txt','w')


def findMissingNumber(inside):
    a = []
    for char in inside:
        for number in char:
            if number in a:
                a.remove(number)
            else:
                a.append(number)
    return a

data=[]
x=int(f.readline())
for a in range(x):
    y=int(f.readline())
    inside = []
    for b in range(2*y-1):
        inside.append(f.readline().strip().split(" "))
    missingList = findMissingNumber(inside)
    for c in range(len(missingList)):
        missingList[c] = int(missingList[c])
    sortMissingList = sorted(missingList)
    for d in range(len(sortMissingList)):
        sortMissingList[d] = str(sortMissingList[d])
    answer = " ".join(sortMissingList)
    print('Case #'+str(a+1)+': '+answer)
    g.write('Case #'+str(a+1)+': '+answer+'\n')

def putInside(inside, currentNumber):
    for i in str(currentNumber):
        inside.append(int(i))
    return inside

g.close()


