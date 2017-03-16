import math
input = open("B-small-attempt1.in")
output = open("output.out","w")

cases = input.readlines()[1:]
t = 0
while cases:
    t += 1
    n,x,y = map(int,cases.pop(0).strip().split())
    h = (abs(x) + y) - 1
    r = 0.0
    if x == 0:
        if n >= ((y + 1) * (y + 2) / 2):
            r = 1.0
        else:
            r = 0.0
    else:
        n -= (h * (h + 1)) / 2
        if n <= 0:
            r = 0.0
        elif n >= y + h + 2:
            r =  1.0
        else:
            s = 0
            for i in range(n - y):
                s += math.factorial(n) / math.factorial(i) / math.factorial(n - i)
            r = s / float(2 ** n)
    print "Case #{}: {}".format(t,r)
    output.write("Case #{}: {}\n".format(t,r))

input.close()
output.close()
