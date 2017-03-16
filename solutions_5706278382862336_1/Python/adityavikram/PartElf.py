from math import log

def gcd(x,y):
    if y==0:
        return x
    return gcd(y,x%y)


if __name__=='__main__':
    T = int(input())
    
    for i in range(1,T+1):
        ans = "Case #"+str(i)+": "
        inp = input().split('/')
        N = int(inp[0])
        D = int(inp[1])
        g = gcd(N,D)
        N = N//g
        D = D//g
        if D&(D-1) != 0:
            ans += 'impossible'
        else:
            ans += str(int(log(D,2))-int(log(N,2)))
        print(ans)
        
        
        
        
