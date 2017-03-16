from random import *

def generate (digits):
    out = 1
    for i in range(digits-2):
        out = out * 10 + randint(0, 1)
    return out * 10 + 1

def divisor (x, base):
    p = 1
    while p * 10 < x:
        p *= 10

    y = 0
    while p >= 1:
        y = y * base + ((x // p) % 10)
        p = p // 10

    if y % 2 == 0:
        return 2
    i = 3
    while i < 100000 and i * i <= y:
        if y % i == 0:
            return i
        i += 2
    return -1

print("Case #1:")

N = 32
J = 500

nums = []
while len(nums) < J:
    x = generate(N)
    if not x in nums:
        divs = []
        for base in range(2, 11):
            d = divisor(x, base)
            if d < 2:
                break
            divs.append(d)
        if len(divs) == 10-2+1:
            nums.append(x)
            print(x, " ".join(str(i) for i in divs))
