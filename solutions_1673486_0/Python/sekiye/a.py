def prob(t, p):
    s = 0
    for i, j in zip(t, p):
        s += i * j
    return s

def solve():
    A, B = map(int, raw_input().split())
    p = map(float, raw_input().split())
    table = []
    keep_typing = [B - A + 1, 2 * B - A + 2, 2 * B - A + 2, 2 * B - A + 2, 2 * B - A + 2, 2 * B - A + 2, 2 * B - A + 2, 2 * B - A + 2]
    backspace_once = [B - A + 3, B - A + 3, 2 * B - A + 4, 2 * B - A + 4, 2 * B - A + 4, 2 * B - A + 4, 2 * B - A + 4, 2 * B - A + 4]
    backspace_twice = [B - A + 5, B - A + 5, B - A + 5, B - A + 5, 2 * B - A + 6, 2 * B - A + 6, 2 * B - A + 6, 2 * B - A + 6]
    enter_right_away = [B + 2, B + 2, B + 2, B + 2, B + 2, B + 2, B + 2, B + 2]
    for i in range(1 << A):
        probability = 1
        for j in range(A)[::-1]:
            if i & 1:
                probability *= 1 - p[j]
            else:
                probability *= p[j]
            i >>= 1
        table.append(probability)
    return min(prob(table, keep_typing), prob(table, backspace_once), prob(table, backspace_twice), prob(table, enter_right_away))

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
