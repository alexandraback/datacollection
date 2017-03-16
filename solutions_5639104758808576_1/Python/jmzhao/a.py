import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def readline(fun) : return [fun(_) for _ in input().split()]
def once():
    '''to cope once'''
    s_max, s = input().split()
    acc = ans = 0
    for i, ch in enumerate(s) :
        if acc < i :
            ans += i - acc
            acc = i
        acc += int(ch)
    return ans

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
