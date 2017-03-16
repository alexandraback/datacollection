import os

os.remove('sub.out')


f = open('B-small-attempt0.in', 'r')

output = open('sub.out','a')
Data = f.read()

Data = Data.split('\n')

T = int(Data[0])
CakeList = Data[1:]

for t in xrange(T):
    cakes = CakeList[t]
    # preprocessing
    newcakes = cakes[0]
    for temp in cakes:
        if temp != newcakes[-1]:
            newcakes += temp
    # counting times
    times = len(newcakes)-1
    if newcakes[-1] == '-':
        times += 1

    writeline = 'Case #'+ str(t+1) + ': '+ str(times)+'\n'
    output.write(writeline)