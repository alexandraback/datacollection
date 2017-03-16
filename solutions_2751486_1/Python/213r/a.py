import sys

def read():
    return sys.stdin.readline()

def format(tup):
    return 'Case #%d: %d'%tup

def chk(s):
    vouels = "aeiou"
    return s in vouels

def do(st,n):
    l = len(st)
    ary = []
    cnt = 0
    for i in xrange(l):
        if chk(st[i]): cnt = 0
        else: cnt += 1
        if cnt >= n:    
            ary.append(i-n+1)
    j = 0
    num = 0
    for i in xrange(l):
        if j < len(ary): 
            if i <= ary[j]:
                num += l - n - ary[j] + 1
                if i == ary[j]: j += 1
    return num

for i in xrange(int(read())):
    st, n = read().split() 
    print format((i+1,do(st,int(n))))

           
