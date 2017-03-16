import sys

def divisor(x):
    if x%2 == 0:
        return 2
    j = 3
    #while j*j <= x:
    while j <= 100:
        if x % j == 0:
            return j
        j += 2
    if j == 100:
        return 100
    return -1

def solve(N, J):
    x = 2**(N-1) + 1
    cnt = 0
    while cnt < J:
        if divisor(x) != -1:
            t = bin(x)[2:]
            divs = []
            for k in range(2,11):
                divs.append( divisor(int(t,k)) )
            if divs.count(-1) == 0:
                print t, " ".join( "%d" % d for d in divs )
                cnt += 1
        while True:
            x += 6
            if bin(x).count('1') %2 == 0:
                break


if __name__ == "__main__":
    print "Case #1:"
    #solve(6,3)
    #solve(16, 50)
    solve(32, 500)

