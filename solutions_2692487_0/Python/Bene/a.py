import sys
sys.stdin = open('a1.in')
sys.stdout = open('a1.out', 'w')
T = input()
def sol():
    a, n = map(int, raw_input().split())
    v = map(int, raw_input().split())
    v.sort()
    ans = n
    now = 0
    i = 0
    while i<n:
        if v[i]<a:
            a += v[i]
            ans = min(ans, now+n-i-1)
            i+=1
        else:
            ans = min(ans, now+n-i)
            if a <= 1:
                break
            a += a-1
            now += 1
    return ans

for ca in range(1, T+1):
    res = sol()
    print 'Case #'+str(ca)+':', res
