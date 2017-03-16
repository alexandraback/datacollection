case = open('file.txt')

t = int(case.readline().rstrip())

for x in range(t):
    r,c,w = map(int, case.readline().rstrip().split())
    ans = 0
    for i in range(r):
        b = c
        while b >= w:
            d = b
            b -= w
            ans += 1
    if d > w:
        ans += 1
    ans += w - 1
    print('Case #{}: {}'.format(x+1,ans))

case.close()
