# import necessary modules

# global variables
X = 0
Y = 0

# helper functions

# read function
def read():
    global X,Y
    temp = raw_input()
    loc = temp.find(' ')
    X = int(temp[:loc])
    Y = int(temp[loc + 1:])

# main logic
def solve(count):
    read()
    aX = abs(X)
    aY = abs(Y)
    sum1 = aX + aY
    n = int ((2 * sum1)**0.5)
    while (n * (n+1)) / 2 < sum1 or ((n * (n + 1) / 2) - sum1) % 2 == 1:
        n += 1
    negatives = []
    positives = []
    x = []
    y = []
    i = n
    temp = ((n * (n + 1)) / 2 - sum1) / 2
    while sum(negatives) < temp:
        if sum(negatives) + i <= temp:
            negatives.append(i)
        i -= 1
    for i in range(1, n + 1):
        if i not in negatives:
            positives.append(i)
    if aX > aY:
        aX += sum(negatives)
    else:
        aY += sum(negatives)
    positives.reverse()
    temp = aY
    temp2 = []
    temp2[:] = positives [:]
    for i in positives:
        if temp == 0:
            break
        if temp - i >= 0:
            temp -= i
            y.append(i)
            temp2.remove(i)
    positives = temp2
    if temp:
        temp2[:] = positives[:]
        positives.extend(y)
        for i in positives:
            if aX == 0:
                break
            if aX - i >= 0:
                aX -= i
                x.append(i)
                temp2.remove(i)
        positivies = temp2
        y = positives
    else:
        x = positives

    aX = abs(X)
    result = ''
    if X < 0:
        east = -1
    else:
        east = 1
    if Y < 0:
        north = -1
    else:
        north = 1
    if aX > aY:
        check = east
        true = 'W'
        false = 'E'
    else:
        check = north
        true = 'S'
        false = 'N'
    for i in range (1, n + 1):
        if i in negatives:
            if check  > 0:
                result += true
            else:
                result += false
        elif i in x:
            if east > 0:
                result += 'E'
            else:
                result += 'W'
        else:
            if  north > 0:
                result += 'N'
            else:
                result += 'S'
    print 'Case #' + str(count) + ':' + ' ' + result
            

def main():
    T = int(raw_input())
    for i in range(T):
        solve(i + 1)

main()
