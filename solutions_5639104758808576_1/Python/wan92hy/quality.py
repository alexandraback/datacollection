import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

def solve():
    [n, s] = input().split()
    a = list(s)
    n = int(n)
    for i in range(n+1):
        a[i] = int(a[i])
    #print(a)
    ans = 0
    now = a[0]
    for i in range(1, n+1):
        if now >= i:
            now += a[i]
        else:
            ans += i - now
            now = i+a[i]
        #print(now, ans)
    return ans

for T in range(int(input())):
    print('Case #%d: %s' % (T+1, solve()))