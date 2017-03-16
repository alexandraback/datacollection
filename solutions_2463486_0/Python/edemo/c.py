import math as m

filename = 'C-small-attempt0.in'

FILE = open(filename)
T = int(FILE.readline())


def isPalindrome(x):
    return str(x) == str(x)[::-1]

def odds(x):
    rList = [0,1,4,9]
    i = 1
    while 1:
        for j in [0,1,2,3,4,5,6,7,8,9]:
            c = int(str(i) + str(j) + str(i)[::-1])
            if isPalindrome(c*c):
                rList.append(c*c)
                if c*c >= x:
                    return rList
        i += 1
    return rList

def evens(x):
    rList = [121]
    i = 2
    while 1:
        c = int(str(i) + str(i)[::-1])
        if isPalindrome(c*c):
            rList.append(c*c)
            if c*c >= x:
                return rList
        i += 1
    return rList

def getAll(x):
    rList = odds(x) + evens(x)
    rList.sort()
    return rList

cache = getAll(10**20)

def count(l,u,c):
    return len([e for e in c if (e <= u and e >= l)])

for i in range(1,T+1):
    rawline = FILE.readline().split(' ')
    a,b = int(rawline[0]), int(rawline[1])

    print('Case #' + str(i) + ': ' + str(count(a,b,cache)))