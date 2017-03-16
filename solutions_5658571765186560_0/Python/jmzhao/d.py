import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def readline(fun) : return [fun(_) for _ in input().split()]
def once():
    '''to cope once'''
    x, r, c = [int(x) for x in input().split()]
    def check() :
        ''' return True if can be filled anyway'''
        if x == 1 :
            return True
        if x == 2 :
            return r * c % 2 == 0
        if x == 3 :
            if max(r, c) < 3 : 
                return False ## bar
            if min(r, c) < 2 :
                return False ## square
            if r * c % 3 != 0 :
                return False
            return True
        if x == 4 :
            if max(r, c) < 4 : 
                return False ## bar
            if min(r, c) <= 2 :
                return False ## square, T-shape
            if r * c % 4 != 0 :
                return False
            return True
    return 'GABRIEL' if check() else 'RICHARD'

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
