table = [
    ["1", "i", "j", "k"],
    ["i", "-1", "k", "-j"],
    ["j", "-k", "-1", "i"],
    ["k", "j", "-i", "-1"]
]

def mul(a, b):
    if a is None: return b
    if b is None: return a
    minus = False
    if (a[0] == "-") != (b[0] == "-"):
        minus = True
    a = "1ijk".index(a[-1])
    b = "1ijk".index(b[-1])
    result = table[a][b]
    if result[0] == "-" and minus:
        return result[-1]
    if minus:
        return "-" + result
    return result

def do_case(x, word):
    x = min(x, x % 4 + 12)
    word = word * x

    sall = None
    for i, char in enumerate(word):
        sall = mul(sall, char)
    if sall != "-1":
        return "NO"

    s = None
    spos = None
    for i, char in enumerate(word):
        s = mul(s, char)
        if s == "i":
            spos = i
            break
    s2 = None
    spos2 = None
    for i, char in enumerate(reversed(word)):
        s2 = mul(char, s2)
        if s2 == "k":
            spos2 = len(word) - i - 1
            break

    if spos is None or spos2 is None:
        return "NO"
    if spos2 <= spos:
        return "NO"
    return "YES"





n = int(input())
for i in range(n):
    l, x = list(map(int, input().split()))
    word = input().strip()
    print("Case #{}: {}".format(i + 1, do_case(x, word)))

