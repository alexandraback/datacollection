def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def is_power2(x):
    return (x & (x - 1)) == 0

def find_pow(x):
    pow=0
    while x > 1:
        x /= 2
        pow+=1
    return pow


def solve():
    a,b = map(int, raw_input().split('/'))
    c=gcd(a,b)
    a/=c
    b/=c
    if is_power2(b) is False:
        ans="impossible"
    else:
        ans=find_pow(b)-find_pow(a)
    return ans


for i in range(int(raw_input().strip())):
    ans = solve()
    print "Case #%d: %s" % (i+1, ans)
