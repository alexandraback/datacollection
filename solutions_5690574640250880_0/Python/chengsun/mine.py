#!/usr/bin/python3

# one square free then yes
# r or c = 1 then yes
# f=m*n squares free and m<=r and n<=c then yes

T = int(input())
for t in range(1,T+1):
    r, c, m = map(int, input().split())
    flipped = False
    if r > c:
        r, c = c, r
        flipped = True
    grid = [[True]*c for y in range(r)]
    f = r*c - m
    if f == 1:
        grid[0][0] = False
    elif r == 1:
        for x in range(f):
            grid[0][x] = False
    else:
        for n in range(2, min(r, f//2)+1):
            a = [n]*2
            def test(nmax, x, f):
                if f == 0:
                    return True
                assert f > 0
                if x == c:
                    return False
                for n in range(2, min(nmax, f)+1):
                    a.append(n)
                    if test(n, x+1, f - n):
                        return True
                    a.pop()
            if test(n, 2, f - n*2):
                for x in range(len(a)):
                    for y in range(a[x]):
                        grid[y][x] = False
                break
    if flipped:
        grid = [[grid[y][x] for y in range(r)] for x in range(c)]
        r, c = c, r
    if grid[0][0]:
        s = "Impossible"
    else:
        s = '\n'.join((''.join(('*' if grid[y][x] else '.' for x in range(c))) for y in range(r)))
        s = 'c' + s[1:]
    print("Case #{}:\n{}".format(t, s))

