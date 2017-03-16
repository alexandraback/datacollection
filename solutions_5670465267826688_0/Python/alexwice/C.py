fi = open('A.in','r')
fo = open('A.out','w')
rr = lambda: fi.readline().replace('\n','')
rrI = lambda: int(rr())
rrM = lambda: map(int,rr().split())
rrS = lambda: rr().split()
#####
def multiply(a,b):
    if a=='1': return b
    if a=='-1':
        if b=='1': return '-1'
        if b=='i': return '-i'
        if b=='j': return '-j'
        if b=='k': return '-k'
        if b=='-1': return '1'
        if b=='-i': return 'i'
        if b=='-j': return 'j'
        if b=='-k': return 'k'
    if a=='i':
        if b=='1': return 'i'
        if b=='i': return '-1'
        if b=='j': return 'k'
        if b=='k': return '-j'
        if b=='-1': return '-i'
        if b=='-i': return '1'
        if b=='-j': return '-k'
        if b=='-k': return 'j'
    if a=='-i':
        if b=='1': return '-i'
        if b=='i': return '1'
        if b=='j': return '-k'
        if b=='k': return 'j'
        if b=='-1': return 'i'
        if b=='-i': return '-1'
        if b=='-j': return 'k'
        if b=='-k': return '-j'
    if a=='j':
        if b=='1': return 'j'
        if b=='i': return '-k'
        if b=='j': return '-1'
        if b=='k': return 'i'
        if b=='-1': return '-j'
        if b=='-i': return 'k'
        if b=='-j': return '1'
        if b=='-k': return '-i'
    if a=='-j':
        if b=='1': return '-j'
        if b=='i': return 'k'
        if b=='j': return '1'
        if b=='k': return '-i'
        if b=='-1': return 'j'
        if b=='-i': return '-k'
        if b=='-j': return '-1'
        if b=='-k': return 'i'
    if a=='k':
        if b=='1': return 'k'
        if b=='i': return 'j'
        if b=='j': return '-i'
        if b=='k': return '-1'
        if b=='-1': return '-k'
        if b=='-i': return '-j'
        if b=='-j': return 'i'
        if b=='-k': return '1'
    if a=='-k':
        if b=='1': return '-k'
        if b=='i': return '-j'
        if b=='j': return 'i'
        if b=='k': return '1'
        if b=='-1': return 'k'
        if b=='-i': return 'j'
        if b=='-j': return '-i'
        if b=='-k': return '-1'

dividedic = {} #dic[(x,y)] = k    equiv to xk = y
for i in ['1','-1','i','-i','j','-j','k','-k']:
    for i2 in ['1','-1','i','-i','j','-j','k','-k']:
        dividedic[(i,multiply(i,i2))] = i2

from itertools import *
def reduce2 (fn, init, seq):
    return reduce(fn, seq, init)

def foldr (function, initial):
    return partial(reduce2, function, initial)
def solve(L,X,A):
    
    dic = {}
    dicR = {}
    cur = '1'
    Lprod = reduce(multiply, A)
    prod = Lprod
    if X%4==2: prod = multiply(prod, prod)
    if X%4==3: prod = multiply(prod,multiply(prod, prod))
    if X%4==0: prod = multiply(prod,multiply(prod,multiply(prod, prod)))
    if prod != '-1': return 'NO'
    #find the first i, and the first k from the end
    #if the sum is < the total length, you're good
    cur = '1'
    flag = False
    ct = 0
    #print L,X,A
    for a in A*min(X,4):
        cur= multiply(cur,a)
        ct += 1
        if cur=='i':
            flag =True
            break
    if not flag: return 'NO'
    cur = '1'
    flag = False
    ct2 = 0
    for a in (A*min(X,4))[::-1]:
        cur= multiply(a,cur)
        ct2 += 1
        if cur=='k':
            flag =True
            break
    if not flag: return 'NO'
    #print ct,ct2
    if ct+ct2 > L*X: return 'NO'
    return 'YES'
#####
for T in xrange(rrI()):
    L,X=rrM()
    A=rr()
    out = 'Case #%i: %s'%(T+1,solve(L,X,A))
    print out
    fo.write(out+'\n')
fo.close()
#####

