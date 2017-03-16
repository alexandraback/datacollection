from sys import stdin

def required_full(x,y):
    z = abs(x) + y
    return sum(range(1,z))

def prob(n, r, x):
    if n == 0: 
        return 1
    if r == 0:
        return 0


    if x == 0:
        return prob(n-1,r-1,0)
    else:
        return 0.5*(prob(n-1,r-1,x) + prob(n,r-1,x-1))

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
