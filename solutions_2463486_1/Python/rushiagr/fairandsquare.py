#a = [int(i) for i in raw_input().split()]
#print a

import math

def palindrome(s):
    return s == s[::-1]

start, end = 1, 10**14
#    startbachha = int(math.ceil(math.sqrt(start)))
#    endbachha = int(math.ceil(math.sqrt(end)))
count = 0
mem = []
for i in xrange(1,10**7+1):
    if i**2 > end or i**2 < start:
        continue
    if palindrome(str(i)):
        if palindrome(str(i**2)):
#            print 'number is ', i**2
            mem.append(i**2)
            count += 1
            
#print 'count', count
#print 'mem', mem, len(mem)
            
times = input()
for time in range(times):
    a = [int(i) for i in raw_input().split()]
    x,y = a[0],a[1]
    thiscount = 0
    for num in mem:
        if num >= x and num <= y:
            thiscount += 1
                
    print 'Case #%d: %d' % ( (time+1), thiscount)