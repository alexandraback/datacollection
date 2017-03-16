fi = open("A.in","r")
x = fi.next()
def f(string):
    res = -1
    for x in range(len(string)-1):
        n,r = string[:x+1].strip('0'),string[x+1:].strip('0')
        n = n[::-1]
        m = int(n)+int(r)
        if n == '1':
            m = m -1
        if res == -1:
            res = m
        else:
            res = min(res, m)
    now = '0'
    res += 1
    if len(string) > 0:
        now = '9'*(len(string)-1)
    return res, now
def solve(string):
    ans = 0
    now = int(string)
    if now % 10 == 0:
        ans = ans + 1
        now = now - 1
    now = str(now)
    while len(now) != 1:
        res, now = f(now)
        ans += res
    ans += int(now)
    return ans
for i,line in enumerate(fi):
    tmp = line.strip()
    num = solve(tmp)
    print "Case #%d: %d" % (i+1,num)
