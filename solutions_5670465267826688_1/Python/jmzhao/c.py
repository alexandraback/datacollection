import sys
import time

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def readline(fun) : 
    return [fun(_) for _ in input().split()]
    
Q = [
    [0,  1,  2,  3,  4],
    [1,  1,  2,  3,  4],
    [2,  2, -1,  4, -3],
    [3,  3, -4, -1,  2],
    [4,  4,  3, -2, -1]
]
ch2q = dict(zip('ijk', (2,3,4)))
def q(a, b) :
    sgn = 1
    if a < 0 : 
        sgn = -1
    if b < 0 :
        sgn *= -1
    return sgn * Q[abs(a)][abs(b)]
def p(xq, x) :
    ans = 1
    for i in range(x%4) :
        ans = q(ans, xq)
    return ans
    
def once():
    '''to cope once'''
#    time.sleep(1)
    l, x = [int(x) for x in input().split()]
    s = input()
    return 'YES' if check(s, x) else 'NO'
    
def check(s, x) :
    acc = 1
    f = list()
    for ch in s :
        acc = q(acc, ch2q[ch])
        f.append(acc)
#    printerr(f)
    final = p(acc, x)
    if final != -1 :
        return False
    hasi = hasj = False
    for _, b in zip(range(x), (1, acc, q(acc,acc), q(acc,q(acc,acc)), 
                          1, acc, q(acc,acc), q(acc,q(acc,acc)))) :
        for a in f :
            if not hasi :
                if q(b, a) == 2 :
                    hasi = True
            elif not hasj :
                if q(b, a) == 4 :
                    hasj = True
                    return True
    return False
    
def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
