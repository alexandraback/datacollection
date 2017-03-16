t = int(input())

def solve(p,q):
    if not power2(q):
        return "impossible"
    count = 0
    n = q
    while (n > p):
        count += 1
        n /= 2
    return count
def power2(n):
    return (n != 0) and ((n & (n - 1)) == 0)
for case in range(1,t+1):
    p,q = map(int,input().split('/'))
    answer = solve(p,q)
    print("Case #{}: {}".format(case,answer))

    

