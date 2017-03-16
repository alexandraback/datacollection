import sys, math, os
import itertools
import json
from gmpy import mpz

def is_palindrome(num):
    n = num
    rev = 0
    while (num > 0):
        dig = num % 10
        rev = rev * 10 + dig
        num = num / 10;
    return n==rev


H = ['1','4','9']

def fair_square(pal):
    p = mpz(pal)
    s = str(p*p)
    if s==s[::-1]:
        H.append(s)

if not os.path.exists('H'):
    for k in xrange(25):
        print k
        # type [''/0/1/2] [0/1]*k 1
        for seq in itertools.product('01', repeat=k):
            fair_square( '1' + ''.join(seq[::-1]) + ''.join(seq) + '1' )
            fair_square( '1' + ''.join(seq[::-1]) + '0' + ''.join(seq) + '1' )
            fair_square( '1' + ''.join(seq[::-1]) + '1' + ''.join(seq) + '1' )
            fair_square( '1' + ''.join(seq[::-1]) + '2' + ''.join(seq) + '1' )
            # type [''/0/1] [0]*k 2
        seq = '0'*k
        fair_square( '2' + ''.join(seq[::-1]) + ''.join(seq) + '2' )
        fair_square( '2' + ''.join(seq[::-1]) + '0' + ''.join(seq) + '2' )
        fair_square( '2' + ''.join(seq[::-1]) + '1' + ''.join(seq) + '2' )

    open('H','w').write(json.dumps(H))
else:    
    H = json.loads(open('H','r').read())

H = map(lambda x: mpz(x), H)
#print H

f=sys.stdin
T = int(f.readline())
for t in xrange(T):
    A, B = f.readline().split()
    a = mpz(A)
    b = mpz(B)
    n = 0
    for x in H:
        if a<=x and x<=b:
            n += 1
    print 'Case #%d: %d'%(t+1,n)
