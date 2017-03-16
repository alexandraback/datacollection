import sys
import fractions
def issecond(x):
    for i in range(40):
        if x == 1:
            return True
        if x == 0:
            return True
        if x % 2 == 1:
            return False
        if x % 2 == 0:
            x /= 2
    return False

def mult(x):
    biggest = 0
    for i in range(1, 41):
        if 2**i < x:
            biggest += 1
        else:
            return biggest

    return biggest

def calc(x, y):
    #first divide

    g = fractions.gcd(x,y)

    x /= g
    y /= g
    divisors = []
    if x == y:
        divisors.append(0)

    if not issecond(y):
        print "impossible"
        return

    for i in range(0, 40):
        if y & 2**i != 0:
            divisors.append(i)
    #else:
    print divisors[0]-mult(x)

T = input()

for t in range(T):
    x,y = [int(i) for i in raw_input().split('/')]

    sys.stdout.write("Case #{}: ".format(t+1) )
    calc(x,y)



