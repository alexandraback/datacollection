import operator
import functools

T = int(input())
for t in range(T):
    A, B = list(map(int, input().split()))
    p = list(map(float, input().split()))
    
    ans = []
    ans += [1 + B + 1] # enter right away
    #ans += [(B - A + 1) * pr + (B - A + + 1 + B + 1) * (1 - pr)] # type on
    for i in range(A + 1): # backspace for i times
        pr = functools.reduce(operator.mul, p[:A - i], 1)
        ans += [(i + B - A + i + 1) * pr + (i + B - A + i + 1 + B + 1) * (1 - pr)]
    print("Case #%d: %f" %(t + 1, min(ans)))
