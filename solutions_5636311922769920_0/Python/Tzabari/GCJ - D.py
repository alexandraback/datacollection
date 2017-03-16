def GetPos(K,C,S):
    if S<(K-C+1):
        return 'IMPOSSIBLE'
    start = 1
    for i in range(1,min(C,K)+1):
        start += (i-1)*(K**(C-i))
    pos = str(start)
    if K>C:
        for i in range(1,K-C+1):
            pos = pos + ' ' + str(start + i)
    return pos


file = 'D-small-attempt0.in'
readf = open(file, 'r')
T = int(readf.readline())
writef = open('Output', 'w')
for i in range(1,T+1):
    line = readf.readline()
    line = line.split()
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])
    pos = GetPos(K,C,S)
    writef.write('Case #' +str(i)+ ': ' + pos + '\n')
writef.close()
readf.close()
