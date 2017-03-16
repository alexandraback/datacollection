import random

def finddiv(n):
    div = 2
    while div*div <= n and div <= 100:
        if n % div == 0: return div
        div += 1
    return -1

T = int(raw_input())
assert T == 1
print("Case #1:")

N, J = map(int, raw_input().split())

knows = set()

num = (1 << (N - 1)) | 1
while len(knows) != J:
    r = random.randint(1, N - 2)
    num ^= 1 << r
    if num in knows: continue

    divs = []
    for i in range(2, 11):
        p = 1
        n = 0
        tmp = num
        while tmp:
            n += p * (tmp % 2)
            tmp /= 2
            p *= i
        divv = finddiv(n)
        if divv > 0: divs.append(str(divv))
        else: break
    if len(divs) == 9:
        print("{} {}".format(bin(num)[2:], ' '.join(divs)))
        knows.add(num)
