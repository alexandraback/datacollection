from string import rstrip
from sys import stdin, stdout

input = []
for line in stdin: input.append(rstrip(line,'\n'))
nTestCases = int(input.pop(0))
testcase = 1
d = 0
while True:
    stdout.write("Case #%s: "%testcase)
    nlevels = int(input.pop(0))
    ones = []
    twos = []
    for level in range(nlevels):
        tokens = input.pop(0).split(' ')
        ones.append([int(tokens[0]), int(tokens[1])])
        twos.append([int(tokens[1]), int(tokens[0])])
    stars = 0
    rounds = 0
    laststars = 0
    toobad = 0
    ones = sorted(ones, key=lambda one: -one[1])
    while 1:
        if d:
            print
            print stars
            print ones
            print twos
        skip = 0
        for i in range(len(twos)):
            if stars >= twos[i][0] and twos[i]:
                stars += 2
                rounds += 1
                skip = 1
                ones.remove([twos[i][1],twos[i][0]])
                twos.pop(i)
                skip = 1
                break
        if skip: continue
        for i in range(len(ones)):
            if stars >= ones[i][0]:
                stars += 1
                rounds += 1
                skip = 1
                if len(ones[i])>1:
                    ones.append([ones[i][1]])
                    twos.remove([ones[i][1],ones[i][0]])
                    ones.pop(i)
                else:
                    ones.pop(i)
                skip = 1
                ones = sorted(ones, key=lambda one: len(one))
                break
        if skip: continue
        if stars == 2*nlevels: break
        else:
            toobad = 1
            break
    if toobad: stdout.write("Too Bad")
    else: stdout.write(str(rounds))
    stdout.write("\n")
    if testcase >= nTestCases: break
    testcase +=1

