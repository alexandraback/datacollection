import math


def getNext():
    global num
    global N
    i = N-2
    while num[i]:
        num[i] = False
        i -= 1
        if i == 0:
            return False
    num[i] = True
    return True

def isPrime(num):
    x = int(math.sqrt(num)+1)
    for i in xrange(2, x):
        if num%i == 0:
            return i, False
    return 0, True


def getAnswer(base):
    global flag
    global num
    global J
    global fp
    n = 0
    for i in num:
        n *= base
        if i:
            n += 1

    div, b = isPrime(n)
    if b:
        return

    if base == 2:
        flag = True
        J -= 1
        for i in num:
            if i:
                fp.write('1')
            else:
                fp.write('0')
        fp.write(" ")

    else:
        getAnswer(base-1)

    if flag:
        fp.write( str(div) )
        #print str(n) + "%" + str(div) + str(" = ") + str(n%div) + "  base = "+ str(base)
        if base == 10:
            fp.write("\n")
        else:
            fp.write(" ")





N = 16
J = 50
flag = False

num = []
for i in xrange(N):
    num.append(False)
num[0] = num[N-1] = True


fp = open("output.txt", "w")


while(J != 0):
    flag = False
    getAnswer(10)
    if not getNext():
        break
print "done"

fp.close()

