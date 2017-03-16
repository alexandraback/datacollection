import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def readline(fun) : return [fun(_) for _ in input().split()]
def once():
    '''to cope once'''
    N = int(input())
    l = [[int(x) for x in input().split()] for _ in range(N)]
    x = tuple()
    y = tuple()
    class T :
        def __init__(self) :
            self.d = 0
            self.t = 0
        def __lt__(self, t) :
            return self.d < t.d or (self.d == t.d and self.t < t.t)
    def fetch(l0) :
        x = T()
        x.d = l0[0]/360
        x.t = l0[-1]
        return x
    if len(l) > 1 :
        x = fetch(l[0])
        y = fetch(l[1])
    else :
        x = fetch(l[0])
        l[0][-1] += 1
        y = fetch(l[0])
    if x > y :
        x, y = y, x
    if x.t > y.t and (1-x.d)*x.t >= (2-y.d)*y.t :
        return 1 ## x is slower
    if x.t < y.t and (1-x.d)*x.t < (1-y.d)*y.t and (1-y.d)*y.t >= (2-x.d)*x.t :
        return 1
    return 0
        
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
