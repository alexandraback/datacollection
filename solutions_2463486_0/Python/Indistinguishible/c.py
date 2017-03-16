import math

def next_pal(n):
    s = str(n)
    beg = int(round(float(len(s)) / 2))
    end = len(s) / 2
    s1 = long(s[:beg])
    if s[:len(s)/2][::-1] <= s[int(round(float(len(s))/2)):]:
        s1 += 1
    s1 = str(s1)
    if len(s1) == beg:
        f = -1 if beg > end else 0
    else:
        f = -2 if beg > end else -1
    s2 = s1[-1+f::-1]
    return long(s1+s2)

def is_pal(n):
    s = str(n)
    for i in range(len(s)/2):
        if s[i] != s[-1*i - 1]:
            return False
    return True

lines = open('c.in').read().split("\n")
f = open('c.out', 'w')

n = int(lines[0])
for i in range(1, n+1):
    res = 0
    a, b = [long(x) for x in lines[i].split()]
    q = next_pal(long(math.ceil(a**0.5))-1)
    end = long(b**0.5)+1
    while q < end:
        if is_pal(q**2):
            res += 1
        q = next_pal(q)
    f.write("Case #%d: %s\n" % (i, res))
    i += 1

f.close()
