def gcd(a,b):
    if a<0 or b<0:
        return "error"
    if a*b == 0:
        return a+b
    return gcd(max(a,b) % min(a,b), min(a,b))

def solve():
    [a,b] = [int(j) for j in raw_input().split('/')]
    c = gcd(a,b)
    [a, b]=[a/c, b/c]
    if a == 0:
        return "impossible"
    if b&(b-1):
        return "impossible"
    else:
        result = 1
        while result*a<b:
            result *= 2
        return len(bin(result)) - 3

for i in range(input()):
    print "Case #{0}: {1}".format(i+1, solve())
