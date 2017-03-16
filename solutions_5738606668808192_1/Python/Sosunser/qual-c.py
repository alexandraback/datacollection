import math

fo = open("c.out","w")

s = list("10000000000000000000000000000001")
res = 0

def gen(i):
    if res == 500:
        return
    if i == 31:
        solve()
        return
    s[i] = "0"
    gen(i+1)
    if res == 500:
        return
    s[i] = "1"
    gen(i+1)
    return

def solve():
    x = [0,0,0,0,0,0,0,0,0,0,0,0]
    for i in range(2,11):
        n = int("".join(s),i)
        if n == 2:
            return
        for y in range(2,min(n-1,10000)):
            if n % y == 0:
                x[i] = y
                break
    for i in range(2,11):
        if x[i] == 0:
            return
    print("".join(s))
    fo.write("".join(s) + " ")
    for i in range(2,11):
        fo.write(str(x[i]) + " ")
    fo.write("\n")
    fo.flush()
    global res
    res += 1
    return

fo.write("Case #1:\n")
gen(1)

