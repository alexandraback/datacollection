T = int(input())
for I in range(1, T+1):    
    r, c, w = [int(x) for x in input().split()]
    first = (r*c) // w
    mod = 1 if c % w > 0 else 0
    result = first + w + mod - 1
    print("Case #%d: %d" % (I, result))   
