def do_case(x, r, c):
    if x == 4 and ((c in [3, 4] and r == 2) or (r in [3, 4] and c == 2)):
        return False
    if x > 6:
        return False
    if x == 1:
        return True
    if x == 2:
        return r % 2 == 0 or c % 2 == 0
    if x == 3:
        return c >= 2 and r >= 2 and (r % 3 == 0 or c % 3 == 0)
    if (x - 1) // 2 + 1 > min(r, c):
        return False
    if x > max(r, c):
        return False
    if (c * r) % x != 0:
        return False
    return True

n = int(input())
for i in range(n):
    x, r, c = list(map(int, input().split()))
    print("Case #{}: {}".format(i + 1, "GABRIEL" if do_case(x, r, c) else "RICHARD"))
