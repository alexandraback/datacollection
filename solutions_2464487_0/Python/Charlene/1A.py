import math

def getArea(radius, count):
    return (radius * 2 + count * 2 - 1) * count

def solve(r, t):
    b = 1 
    e = t + 1

    while (b < e) :
       mid = (b + e) / 2 + 1
       area = getArea(r, mid)
       
       if (area == t):
           return mid
       if (area <= t):
           b = mid
       else:
           e = mid - 1
    
    return b
    
    # n = input()
    # c = [0] * 1001;
    # for x in map(int, raw_input().split()):
    #     c[x] += 1
    
n = input()
for index in range(n):
    r, t = map(long, raw_input().split())
    
    ans = solve(r, t)
    
    result = "Case #%s: %s" % (index + 1, ans)
    print result

