imposs = "Impossible"

def solve(testNum):
    print("Case #%d:"%testNum)
    r,c,m = [int(x) for x in input().split()]
    grid = [['.' for x in range(c)] for y in range(r)]
    if r == c == 1:
        assert m == 0
        print("c"); return
    elif r == 1 and c >= 2:
        if m <= c - 1:
            print('*'*m+'.'*(c-m-1)+'c'); return
        else:
            print(imposs); return
    elif c == 1 and r >= 2:
        if m <= r - 1:
            print('*\n'*m+'.\n'*(r-m-1)+'c'); return
        else:
            print(imposs); return
    else:
        assert r >= 2 and c >= 2
        if m == r*c - 1:
            print('\n'.join(["c"+"*"*(c-1)]+["*"*c for i in range(r-1)])); return
        if m <= r*c - 4:
            "2 <= l <= r && 2 <= w <= c && 2*(l+w-2) <= r*c-m <= l*w"
            "l + w <= (r*c-m)/2 + 2"
            lpc = (r*c-m)//2 + 2
            l = lpc//2
            w = lpc-l
            assert l >= 2 and w >= 2
            #assert l <= r or w <= c
            if l > r:
                l = r
                w = lpc-l
            elif w > c:
                w = c
                l = lpc-w
            if l > r: l = r
            if w > c: w = c
            if r*c-m <= l*w:
                for y in range(l,r):
                    for x in range(c):
                        grid[y][x] = '*'
                        m -= 1
                for y in range(l):
                    for x in range(w,c):
                        grid[y][x] = '*'
                        m -= 1
                for y in reversed(range(2,l)):
                    for x in reversed(range(2,w)):
                        if m > 0:
                            grid[y][x] = '*'
                            m -= 1
                grid[0][0] = 'c'
                print('\n'.join([''.join(row) for row in grid])); return
            else:
                print(imposs); return
        else:
            print(imposs); return

for i in range(1,int(input())+1): solve(i)
