def solve(p):
    res = height = max(p)
    while height:
        h, c = 0, 0
        for x in p:
            k = (x + height - 1)//height
            h = max(h, (x + k - 1)//k)
            c += k - 1
        res = min(res, c + h)
        height -= 1
    return res
                
t = int(input())
output = 'Case #{}: {}'
for i in range(t):
    d = int(input())
    p = [int(x) for x in input().split()]
    print(output.format(i + 1, solve(p)))
