import sys

def dbgprint(func):
    def newfunc(*args, **kwds):
        ret = func(*args, **kwds)
        print(args, '->', ret, file=sys.stderr)
        return ret
    return newfunc

#@dbgprint
def calc(a,b):
    if a==1 and len(b)==1:
        return int(b)
    if b=='1'+'0'*(a-1):
        return 0
    if a==1 and len(b)>1:
        return calc(a, '9'*(len(b)-1))+1+calc(len(b), b)
    if a==len(b):
        l=int(a/2) #l>=1
        if b[:l]=='1'+'0'*(l-1):
            return int(b[l:])
        if b[l:]!='0'*(a-l):
            return int(b[l:])+int(b[:l][::-1])
        return calc(a,str(int(b)-1))+1
    raise 'ERR'

def case(i):
    ln1=sys.stdin.readline();
    a1=str(int(ln1))
    print("Case #"+str(i)+": "+str(calc(1, a1)))

if __name__ == "__main__":
    n=int(sys.stdin.readline())
    [case(i) for i in range(1,n+1)]
