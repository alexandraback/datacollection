from itertools import combinations

input()
N, J = (int(i) for i in input().split())

def check(num):
    if type(num) == int:
        num = [num]

    n = "".join(str(int(i)) for i in num)
    if len(n) != N or n.strip("01") != "":
        return False

    for i in range(2, 11):
        a = int(n, i)
        if a % (i + 1) or i + 1 == a:
            return False

    return True

def combs(f, t):
    for i in range(f, t):
        for j in combinations(range(f, t), i):
            yield j


print("Case #1:")
for i, j in enumerate(combs(1, N//2 - 1)):
    if i >= J:
        break

    pole = [False] * N
    pole[0] = True
    pole[N - 1] = True
    for i in j:
        pole[2 * i] = pole[2 * i + 1] = True

    assert(check(pole))
    print("".join(str(int(a)) for a in pole), "3 4 5 6 7 8 9 10 11")
