def answer(r, n):
    a1 = 2 * r + 1
    an = a1 + 4 * (n - 1)
    return (a1 + an) * n // 2

def solve(num):
    r, t = map(int, input().split())
    left = 1
    right = t + 1
    while right > left + 1:
        middle = (left + right) // 2
        if answer(r, middle) <= t:
            left = middle
        else:
            right = middle
    print("Case #", num, ": ", left, sep='')

T = int(input())
for num in range(1, T + 1):
    solve(num)

