def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

f = open ("A-large.in")
n = int(f.readline())
for i in range(0, n):
    r, t = [int(x) for x in f.readline().split()]    
    x = isqrt(4*r*r + 8*t)
    x = int((1 - 2*r + x) / 4)
    while x * (2*r + 1) + 2*x*(x-1) > t:
        x = x -1
    print("Case #"+str(i+1)+": "+str(x))
