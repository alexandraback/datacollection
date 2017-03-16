import math

def limit(x):
    temp = x/2
    return (2*temp*temp+3*temp+1)

def prob(m, n, x):
    if(n-x > m and x < m):
        return 0.0
    if(n > m):
        return prob(m-1, n-2, x-1)
    return pow(0.5, n)*math.factorial(n)/math.factorial(x)/math.factorial(n-x);
    
def func(n, x, y):
    add = abs(x) + abs(y)
    if(add == 0):
        return 1.0
    
    temp = limit(add-2)
    if(n <= temp):
        return 0.0
        
    if(n >= limit(add)):
        return 1.0
    
    if(x == 0 and n < limit(add)):
        return 0.0
        
    if(n-temp <= abs(y)):
        return 0.0
    
    if(n-temp > abs(y) + add/2+1):
        return 1.0
    
    res = 0.0
    for i in range(0, abs(y)+1):
        res += prob(add, n-temp, i)
    return 1-res

t = int(input())

for CASE in range(1, t+1):
    x = input().split()
    N = int(x[0])
    X = int(x[1])
    Y = int(x[2])
    
        
    print("Case #%d: %f"%(CASE, func(N, X, Y)))