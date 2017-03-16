import math

n = 32
target = 500
cnt = 0
st = []

nums = [0, 0]
for i in range(2, 11):
    nums.append(1 + i ** (n - 1))


def is_prime(a):
    x = int(math.sqrt(a)) + 1
    i = 2
    while i <= x and i <= 100:
        if a % i == 0:
            return i
        i += 1
    return 1


def gen(ps):
    global cnt
    if cnt >= target:
        return
    if ps == n - 1:
        divs = []
        fl = False
        for i in range(2, 11):
            cur = is_prime(nums[i])
            divs.append(cur)
            fl |= cur == 1
        if not fl:
            cnt += 1
            s = "1" + "".join([str(x) for x in reversed(st)]) + "1"
            print(s, " ".join([str(x) for x in divs]))
        return
    for x in range(0, 2):
        st.append(x)
        for i in range(2, 11):
            nums[i] += x * i ** ps
        gen(ps + 1)
        st.pop()
        for i in range(2, 11):
            nums[i] -= x * i ** ps

print("Case #1:")
gen(1)
