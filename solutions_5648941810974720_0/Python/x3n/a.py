from collections import Counter

dic = [
    (8, 'G', "EIGHT"),
    (0, 'Z', "ZERO"),
    (2, 'W', "TWO"),
    (3, 'T', "THREE"),
    (4, 'R', "FOUR"),
    (6, 'X', "SIX"),
    (5, 'F', "FIVE"),
    (1, 'O', "ONE"),
    (7, 'V', "SEVEN"),
    (9, 'N', "NINE")]

def dec1(c, character, string, n):
    ans = 0
    while c[character] > 0:
        ans += 1
        for ch in string:
            c[ch] -= 1
    return ans

def decode(s):
    global dic

    c = Counter(s)
    ans = [0] * 10

    for d in dic:
        ans[d[0]] = dec1(c, d[1], d[2], d[0])

    return ans

t = int(input())

for i in range(t):
    s = input().rstrip()
    ans = ''.join(str(i) * x for i, x in enumerate(decode(s)))
    print("Case #{0}: {1}".format(i + 1, ans))
