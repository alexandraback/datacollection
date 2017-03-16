import math



def gain(vals, limit, regain, curr):
    if len(vals)==1: return vals[0]*curr
    else:
        t=[vals[0]*i + gain(vals[1:], limit, regain, min(curr-i+regain, limit)) for i in range(curr+1)]
        return max(t)


if __name__=='__main__':
    T=int(input())
    for i in range(T):
        [E,R,N]=[int(e) for e in input().split()]
        vals=[int(e) for e in input().split()]
        ans=gain(vals,E,R,E)
        print("Case #"+str(i+1)+": "+str(ans))
