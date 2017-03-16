def cmp1(s1, s2):
    if s1[1] != s2[1]:
        return cmp(s1[1], s2[1])
    else:
        return -1 * cmp(s1[0], s2[0])

def solve():
    N = int(raw_input())
    table = []
    stars = 0
    count = 0
    for i in xrange(N):
        a, b = map(int, raw_input().split())
        if b == 0:
            stars += 2
            count += 1
        else:
            table.append((a, b))
    while len(table) > 0:
        cur = count
        table.sort(cmp=cmp1)
        for a, b in table[:]:
            if b <= stars:
                if a != 1000000:
                    stars += 2
                else:
                    stars += 1
                count += 1
                table.remove((a, b))
        if len(table) == 0:
            return count
        min_a = 2002
        max_b = 0
        min_index = 0
        for i in range(len(table)):
            a, b = table[i]
            if a < min_a or (a == min_a and b > max_b):
                min_a = a
                max_b = b
                min_index = i
        a, b = table[min_index]
        if a <= stars:
            table.pop(min_index)
            table.append((1000000, b))
            stars += 1
            count += 1
        if cur == count:
            return "Too Bad"
    return count

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
