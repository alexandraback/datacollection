from math import sqrt, ceil

def palindrome(s):
    return s == s[::-1]

array = []

def precompute():
    
    a = 1
    b = 10 ** 14

    start = int(ceil(sqrt(a)))
    limit = int(ceil(sqrt(b)))

    for x in range(start,limit+1):
        if(palindrome(str(x))):
            square = x*x
            if(palindrome(str(square)) and square <= b): 
                array.append(square)

def do_thing(index):

    a,b = raw_input().split()
    a,b = int(a), int(b)

    count = 0


    for x in array:
        if(x >= a and x <=b):
            count = count + 1
#    for x in range(a,b+1):
        #if(x in array):

    print "Case #%d: %d" % (index + 1, count)

n = raw_input()
n = int(n)

precompute()

for i in range(n):
    do_thing(i)

