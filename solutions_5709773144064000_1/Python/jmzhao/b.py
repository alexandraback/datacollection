import sys

def printerr(*v):
    print(*v, file=sys.stderr)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    c, f, x = tuple(float(x) for x in input().split())
    
    t = 0; r = 2;
    while (x-c)/r > x/(r+f) :
        t += c/r
        r += f
    t += x/r
    
    return t

def ans2str(ans):
    return str(ans)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, ans2str(ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
