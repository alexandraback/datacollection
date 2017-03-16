#still a mess
import sys

#from math import pi, sqrt
import decimal

decimal.getcontext().prec = 40

def pmult(a,b):
#a, b strictily in '1, i ,j, k'
        if a == '1':
                return b
        if b == '1':
                return a
        if a == b:
                return '-1'
        if a == 'i':
                if b == 'j':
                        return 'k'
                if b == 'k':
                        return '-j'
        if a == 'j':
                if b=='i':
                        return '-k'
                if b =='k':
                        return 'i'
        if a == 'k':
                if b == 'i':
                        return 'j'
                if b == 'j':
                        return '-i'
        else:
                return 'wrong letter'
                

def mult(a,b):
        if a[0] == '-':
                if b[0] == '-':
                        return pmult(a[1], b[1])
                else:
                        p= pmult(a[1], b)
                        if p[0] == '-':
                                return p[1]
                        else:
                                return '-' + p
        else:
                if b[0] == '-':
                        p = pmult(a, b[1])
                        if p[0] == '-':
                                return p[1]
                        else:
                                return '-' + p
                else:
                        return pmult(a,b)
                
def multiplylist(l, L, X): #multipyl long repititve lists, maybe buggy
        k = len(l) // X
        q = len(l) % X
        if k <= 1:
                return mlist(l)
        else:
                r = mlist(l[:L])
                r = mlist([r]*k)
                t = mlist(l[-q:])
                return mult(r,t)

def mlist(l):
        u = '1'
        for e in l:
                u = mult(u, e)
        return u
                        
def findk(l, L, X): #backwards as pop is fastt
        u = '1'
        while l:
                #print e, u
                e = l.pop()
                #print e, u
                u = mult(e, u) 
                #print u, l
                if u == 'k':
                        #print 'k found', len(l) #, l
                        return findj(l, L, X)
        return 'NO'

def findj(l, L, X): #backwards as pop is fastt
        u = '1'
        while l:
                #print e, u
                e = l.pop()
                u = mult(e, u) #if first iterate gives no i we can skip rest!
                if u == 'j':
                        #print 'j found', len(l) #, l
                        if mlist(l) == 'i': #multiplylist(l, L, X) == 'i':
                                #print 'i found, woot!'
                                return 'YES'
                        else:
                                return 'NO'
        return 'NO'
        
def Next(s, L, X):
        # Whatever needs to be done
        #print s
        return findk(s, L, X)
        
####		

input = open(r'./C-small-attempt1.in')
#input = open(r'./C-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[int(j) if j.isdigit() else list(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []

N=2

j = 0

#C=10
for i in xrange(C):
	L, X = Y[2*i]
	s=[]
	for j in range(X): s.extend(Y[2*i+1][0])
	sol += [Next(s, L, X)]
	print 'case ', i, 'done'
	#if not i % 100: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./output1.log', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
	
	
	
	
	
	
	
	
