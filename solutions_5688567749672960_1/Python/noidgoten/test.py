input = open("cocu.in", "r")
output = open("cocu.out", "w")

def flip(k):
    r = 0
    while k != 0:
        r *= 10
        r += k%10
        k = int(k/10)
    return r

def leng(n):
    res = 0
    while n !=0:
        res += 1
        n = int(n/10)
    return res

def right(n):
    res = 0
    i = 1
    for k in range(int(leng(n+1)/2)):
        res += (n % 10) * i
        n = int(n/10)
        i *= 10
    return res

def solve(n):
    res = 1
    while n != 1:
        if n % 10 != 0:
            if n < 10:
                res += n - 1
                n = 1
            else:
                r = right(n)
                if r == 1:
                    if flip(n) == n:
                        n -= 1
                        res += 1
                    else:
                        n = flip(n)
                        res += 1
                else:
                    n = n-r+1
                    res += r
                    if flip(n) < n:
                        n = flip(n)
                    elif n == flip(n):
                        n -= 1
        else:
            n -= 1
            res += 1
    return res

t = int(input.readline())

for i in range(t):
    n = int(input.readline())
    res = solve(n)
    output.write("Case #" + str(1+i) + ": " + str(res) + "\n")

