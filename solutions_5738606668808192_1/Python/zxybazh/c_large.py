def toBase2(x):
    if (x == 0): return "0"
    ans = ""
    while x > 0:
        ans += str(x % 2)
        x /= 2
    return ans[::-1]

def prime(x):
    i = 1
    while (True):
        i += 1
        if (i > 10 or i * i > x): break
        if x % i == 0: return i
    return -1

print "Case #1:"
count = 0
i = 2l**31 - 1
while (i < 2l**32):
    i += 2
    s = toBase2(i)
    d = [prime(i)]
    if (d[0] == -1): continue
    flag = True
    for j in xrange(3, 11):
        d.append(prime(int(s, j)))
        if (d[-1] == -1):
            flag = False
            break
    if (flag):
        print s,
        for w in d: print w,
        print
        count += 1
        if count == 500:
            break
