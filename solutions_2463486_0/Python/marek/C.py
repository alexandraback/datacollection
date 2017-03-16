import sys
import itertools
import collections

'''
import math

A = 10**14
B = long(math.ceil(math.sqrt(A)))

ispalindrome = lambda a: a[::-1] == a

print 'good = ['
for p in (pow(a, 2) for a in xrange(B)):
    a = list(str(p))
    if ispalindrome(a) and ispalindrome(str(long(math.sqrt(p)))):
        print '    ', ''.join(a), ','
print ']'
'''

good = [
     0 ,
     1 ,
     4 ,
     9 ,
     121 ,
     484 ,
     10201 ,
     12321 ,
     14641 ,
     40804 ,
     44944 ,
     1002001 ,
     1234321 ,
     4008004 ,
     100020001 ,
     102030201 ,
     104060401 ,
     121242121 ,
     123454321 ,
     125686521 ,
     400080004 ,
     404090404 ,
     10000200001 ,
     10221412201 ,
     12102420121 ,
     12345654321 ,
     40000800004 ,
     1000002000001 ,
     1002003002001 ,
     1004006004001 ,
     1020304030201 ,
     1022325232201 ,
     1024348434201 ,
     1210024200121 ,
     1212225222121 ,
     1214428244121 ,
     1232346432321 ,
     1234567654321 ,
     4000008000004 ,
     4004009004004 ,
]



for case_no in xrange(0, input()):
    print >> sys.stderr, "Case #%s:" % (case_no + 1,)
    print "Case #%s:" % (case_no + 1,),

    A, B = map(long, raw_input().split())
    c = 0
    for p in good:
        if p >= A and p <= B:
            c += 1
    print c
