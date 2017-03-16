from sys import stdin
import math

def required_full(x,y):
    z = abs(x) + y
    return sum(range(1,z))

def choose(n,k):
    return math.factorial(n) / math.factorial(k) / math.factorial(n-k)
        

def prob(n, r, x):
    if n == 0: 
        return 1
    if r == 0:
        return 0
    if r - n - x >= 0:
        return 1
    if n > r:
        return 0
    return sum([choose(r,k) for k in range(n+1,r+1)]) * 0.5**r
    

    # if x == 0:
    #     return prob(n-1,r-1,0)
    # else:
    #     return 0.5*(prob(n-1,r-1,x) + prob(n,r-1,x-1))



def solve(n,x,y):
    if n >= required_full(x,y+2):
        return 1.0
    if x == 0:
        return 0.0

    n -= required_full(x,y)
    if n < 0: 
        return 0.0

    return prob(y+1, n, abs(x) + y)
    

def main():
    t = int(stdin.readline().strip())

    for c in range(1,t+1):
        (n,x,y) = [int(x) for x in stdin.readline().strip().split()]
        print "Case #%d: %f" % (c, solve(n,x,y))

if __name__ == '__main__':
    main()
