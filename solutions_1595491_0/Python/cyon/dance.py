import sys

def fmod(mo):
    if mo==1: return 0
    return 1

def solve():
    li=map(int,raw_input().split())
    N=li.pop(0)
    S=li.pop(0)
    p=li.pop(0)
    cnt=0
    for i in xrange(0,len(li)):
        z=(li[i]+2)//3
        if z >= p:
            cnt=cnt+1
        else:
            if S>0 and li[i]!=0 and z+fmod(li[i]%3) >= p:
                cnt=cnt+1
                S=S-1
    return cnt

if __name__ == "__main__":
    t=input()
    for c in xrange(0,t):
        print "Case #{0}: {1}".format(c+1, solve())
