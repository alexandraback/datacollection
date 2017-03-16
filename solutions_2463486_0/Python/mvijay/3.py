import numpy
import math

def nextPalindrome(a):
    length = len(str(a))
    oddDigits = (length%2!=0)
    leftHalf = str(a)[:len(str(a))/2]
    middle = str(a)[(len(str(a))-1)/2]
    if oddDigits:
        increment = pow(10, length/2)
        newA = int(leftHalf + middle + leftHalf[::-1])
    else:
        increment=int(1.1*pow(10, length/2))
        newA=int(leftHalf + leftHalf[::-1])
    if newA > a:
        return newA
    if middle != '9':
        return newA + increment
    else:
        return nextPalindrome(roundUp(a))
 
 
def roundUp(num):
    length=len(str(num))
    increment=pow(10,((length/2)+1))
    return ((num/increment)+1)*increment

n = int(raw_input(""))

def checkPalin(a):
    astr = str(a)
    return astr == astr[::-1]


# for i in range(0,n):
#     num = 0    
#     a, b = map(int, raw_input("").split())

#     if not checkPalin(a):
#         a = nextPalindrome(a)
#     while True:
#         if a > b:
#             break
#         sq = math.sqrt(a)
#         if sq.is_integer():
#             if checkPalin(int(sq)):
#                 num += 1
#         a = nextPalindrome(a)

#     print "Case #%d: %d"%(i+1, num)
    
for i in range(0,n):
    num = 0    
    a, b = map(int, raw_input("").split())
    sa = math.sqrt(a)
    if not sa.is_integer():
        sa = int(sa+1)
    else:
        sa = int(sa)
    if not checkPalin(sa):
        sa = nextPalindrome(sa)
    while True:
        sqa = sa*sa
        if sqa > b:
            break

        if checkPalin(int(sqa)):
            num += 1
        sa = nextPalindrome(sa)

    print "Case #%d: %d"%(i+1, num)
