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
    #print "next"
    return True

def isPrime(num, base):
    global J
    x = int(math.sqrt(num)+1)
    for i in xrange(2, 10000):
        if num%i == 0:
            return i, False
    """
    i = 2
    while( i != x ):
        if num%i == 0:
            return i, False
        i += 1
    """
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

    #print "Enter isPrime base = "+ str(base)
    div, b = isPrime(n, base)
    #print "Leave isPrime"
    
    if b:
        return

    if base == 2:
        flag = True
        print "J = "+ str(J) + "b = "+ str(b)
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





N = 32
J = 500
flag = False

num = []
for i in xrange(N):
    num.append(False)
num[0] = num[N-1] = True


fp = open("output.out", "w")
fp.write("Case #1: \n")

while(J != 0):
    flag = False
    getAnswer(10)
    if not getNext():
        print "Fail J = "+ str(J)
        break
print "done"

fp.close()

