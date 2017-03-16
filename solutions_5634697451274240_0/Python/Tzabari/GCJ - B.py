def CountFlips(stack):
    stack = stack[::-1]
    stack = ''.join(stack.split())
    count = 0
    if stack[0] == '-':
        count = 1
    for i in range(1,len(stack)):
        if stack[i] != stack[i-1]:
            count+=1
    return count

file = 'B-small-attempt0.in'
readf = open(file, 'r')
N = int(readf.readline())
writef = open('Output', 'w')
for i in range(1,N+1):
    stack = readf.readline()
    flips = CountFlips(stack)
    writef.write('Case #'+str(i)+': '+str(flips)+'\n')
writef.close()
