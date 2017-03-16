def solve(s):
    cur = '+'
    flips = 0
    for p in reversed(s):
        if p != cur:
            flips+=1
            cur = p
    return flips

n = int(input())
for i in range(n):
    print("Case #%d: %d"%(i+1,solve(input())))
