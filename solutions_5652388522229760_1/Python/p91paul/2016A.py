def solve(k):
    if k == 0: return "INSOMNIA"
    found = [False] * 10
    cur = 0
    while False in found:
        cur += k
        for x in str(cur):
            found[int(x)] = True
    return str(cur)

n = int(input())
for i in range(n):
    print("Case #%d: %s"%(i+1,solve(int(input()))))
