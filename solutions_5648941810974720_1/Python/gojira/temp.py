key = [
    (0, 'Z'),
    (2, 'W'),
    (6, 'X'),
    (7, 'S'),
    (5, 'V'),
    (4, 'F'),
    (8, 'G'),
    (3, 'T'),
    (9, 'I'),
    (1, 'O')
]

digits = {
    0: 'ZERO',
    1: 'ONE',
    2: 'TWO',
    3: 'THREE',
    4: 'FOUR',
    5: 'FIVE',
    6: 'SIX',
    7: 'SEVEN',
    8: 'EIGHT',
    9: 'NINE'
}


def solve(s):
    cnt = {}
    for c in s:
        cnt[c] = cnt.get(c, 0) + 1
    ans = {}
    for tuple in key:
        digit = tuple[0]
        char = tuple[1]
        ans[digit] = cnt.get(char, 0)
        if ans[digit] > 0:
            for c in digits[digit]:
                cnt[c] -= ans[digit]
    ret = ''
    for x in ans:
        for i in range(ans[x]):
            ret += str(x)
    return ret


t = int(raw_input())
for i in range(1, t + 1):
    s = raw_input()
    print 'Case #{}: {}'.format(i, solve(s))
