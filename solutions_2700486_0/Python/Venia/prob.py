#from functools import lru_cache
from fractions import Fraction
from copy import copy

def sim(n):
    s = {(0, 0)}
    for i in range(20):
        s.add((2*i+1, -1))
        s.add((-2*i+1,-1))
        
    d = [(s, 1)]
    for i in range(n-1):
        dd = []
        for pos, P in d:
            i = 0
            while (0, i+2) in pos:
                i += 2

            if (1, i+1) in pos and (-1, i+1) in pos:
                cp = copy(pos)
                cp.add((0, i+2))
                dd.append((cp, P))

            elif (1, i+1) in pos and (-1, i+1) not in pos:
                cp = copy(pos)
                x, y = -1, i+1
                while (x-1, y-1) not in pos:
                    x, y = x-1, y-1
                cp.add((x, y))
                dd.append((cp, P))
                
            elif (1, i+1) not in pos and (-1, i+1) in pos:
                cp = copy(pos)
                x, y = 1, i+1
                while (x+1, y-1) not in pos:
                    #print(x, y)
                    x, y = x+1, y-1
                cp.add((x, y))
                dd.append((cp, P))

            else:
                cp1 = copy(pos)
                cp2 = copy(pos)
                x, y = 1, i+1
                while (x+1, y-1) not in pos:
                    #print(x, y)
                    x, y = x+1, y-1
                cp1.add((x, y))
                dd.append((cp1, P*Fraction(1, 2)))

                x, y = -1, i+1
                while (x-1, y-1) not in pos:
                    #print(x, y)
                    x, y = x-1, y-1
                cp2.add((x, y))
                dd.append((cp2, P*Fraction(1, 2)))
            d = dd
    return d


ds = [None] + [sim(i) for i in range(1, 21)]

def silly_prob(x, y, n):
    d = ds[n]
    res = 0
    for poss, P in d:
        if (x, y) in poss:
            res += P
    return res


T = int(raw_input())

for i in range(T):
    n, x, y = map(int, raw_input().split())
    print("Case #{}: {}".format(i+1, float(silly_prob(x, y, n))))

#@lru_cache(maxsize = None)
def prob(x, y, n):
    print(x, y, n)
    if y == -1 and x%2 == 1: return 1
    elif n == 1:
        return 1 if (x, y) == (0, 0) else 0
    elif x < 0:
        return prob(-x, y, n-1)
    elif x > 0:
        res = prob(x, y, n-1) # it's already there

        if y != 0:
            return 
            res + (1-prob(x, y, n-1))  * prob(x+1, y-1, n-1) # right down must be there
        # if RD is there, LD and R are also there
                
        return res
    else:
        # x = 0
        # 
        return prob(x, y, n-1) + (1-prob(x, y,n-1))*prob(x-1, y-1, n-1)*prob(x+1, y-1, n-1)
