import math

f=open('A-small-attempt0.in', 'r')
g=open('outputsmall.txt','w')

data=[]
x=int(f.readline())
for a in range(x):
    data.append(f.readline().strip())

print(data)

def compareString(x, y):
    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    return alphabet.index(x)>=alphabet.index(y)

def putInside(inside, currentNumber):
    for i in str(currentNumber):
        inside.append(int(i))
    return inside


for a in range(x):
    b = data[a]
    m = [b[0]]
    for i in range(len(b)-1):
        if compareString(b[i+1], m[0]):
            m.insert(0, b[i+1])
        else:
            m.append(b[i+1])
    n = "".join(m)
    print('Case #'+str(a+1)+': '+n)
    g.write('Case #'+str(a+1)+': '+n+'\n')

g.close()


