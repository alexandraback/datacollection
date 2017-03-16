# def sol1(a, b):
#     a, b = set(a), set(b)
#     r = a & b
#     if len(r) > 1:
#         return 'Bad magician!'
#     if len(r) == 0:
#         return 'Volunteer cheated!'
#     return r.pop()
_eps = 1e-6 

def sol2(C, Fx, X, r = 2):
    c1 = C / X
    i = 0
    g = c1 - 1 + (r + Fx * i)/(r + Fx * i + Fx)
    t = 0
    # print i, g
    while (g < 0):
        t += C / (r + Fx * (i))
        i += 1
        g = c1 - 1 + (r + Fx * i)/(r + Fx * i + Fx)
        # print i, g
    # print 'time:', t
    return min(t + X/(r + Fx * (i)), t + C/(r + Fx * i) + X/(r + Fx + Fx * i))

def sol22(C, Fx, X, r = 2):
    c1 = C - X
    c2 = X/Fx
    i = 1
    g = c1 + c2 * (r + Fx * i)/float(i+1)
    t = 0
    while (abs(g) < _eps and i <= int(X/Fx) + 1):
        t += C / (r + Fx * i)
        i *= 2
        g = c1 + c2 * (r + Fx * i)/float(i+1)
    return 
    
        

import sys
readline = sys.stdin.readline

tn = int(readline())
for i in xrange(1, tn + 1):
    C, Fx, X = map(float, readline().split(" "))
    # print '=' * 80
    print 'Case #{}: {:.07f}'.format(i, sol2(C, Fx, X))
