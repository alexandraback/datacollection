a = []
a.append(1)
a.append(2)
a.append(3)
def revInt(x):
    ret = 0
    while (x):
        ret = ret * 10 + x % 10
        x //= 10
    return ret
def binToDec(x):
  s = bin(x)[2:]
  return int(s)
def isPal(x):
    if (x % 10 == 0): return False
    return x == revInt(x)
def checkNum(x):
    if (isPal(x) and isPal(x * x)): a.append(x)
def pr(l):
    e = l // 2
    lef = 1<<(e-1)
    rig = 1<<e
    pw = 10**e
    for i in range(lef, rig):
        x = binToDec(i)
        if (l % 2):
            checkNum(x * pw * 10 + revInt(x))
            checkNum(x * pw * 10 + pw + revInt(x))
            checkNum(x * pw * 10 + 2 * pw + revInt(x))
        else:
            checkNum(x * pw + revInt(x))
    if (l % 2):
        checkNum(2 * pw * pw + 2)
        checkNum(2 * pw * pw  + pw + 2)
    else:
        checkNum(2 * pw * pw // 10 + 2)
for i in range(2, 9): pr(i)
print("yes boss")
t = int(input())
for i in range(1, t + 1):
    L, R = map(int, input().split())
    ans = 0
    for j in a:
        if (j * j > R): break
        if (L <= j * j): ans += 1
    print("Case #", i, ": ", ans, sep = "")