def CountSheeps(n):
    if int(n) == 0:
        return 'INSOMNIA'
    digitList = []
    i = 1
    while len(digitList) < 10:
        k = str(int(n)*i)
        for digit in k:
            if digit not in digitList:
                digitList.append(digit)
        i += 1
    return k
    


file = 'A-large.in'
readf = open(file, 'r')
N = int(readf.readline())
writef = open('Output', 'w')
for i in range(1,N+1):
    num = readf.readline()
    lastNum = CountSheeps(num)
    writef.write('Case #'+str(i)+': '+str(lastNum)+'\n')
writef.close()
