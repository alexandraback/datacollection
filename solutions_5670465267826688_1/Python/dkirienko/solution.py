MUL = {"ij":"k", "ji":"-k", "ik":"-j", "ki":"j", "jk":"i", "kj":"-i", "ii":"-1", "jj":"-1", "kk":"-1"}

def mul(q1, q2):
    res = ""
    for c in q1 + q2:
        if "a" <= c <= "z":
            res += c
    if len(res) == 2:
        res = MUL[res]
    res = "-" * (q1 + q2).count("-") + res
    if res[:2] == "--":
        res = res[2:]
    if res == "" or res == "-":
        res = res + "1"
    # if res not in ["1", "-1", "i", "-i", "j", "-j", "k", "-k"]: res = "FAIL"
    return res

"""
for q1 in ["1", "i", "j", "k"]:
    q1 = mul("-1", q1)
    for q2 in ["1", "i", "j", "k"]:
        q2 = mul("-1", q2)
        print(mul(q1, q2).center(5), end=" ")
    print()
"""

def solve():
    L, X = map(int, input().split())
    S = input()
    prod = "1"
    for elem in S:
        prod = mul(prod, elem)
    if prod == "1":
        return "NO"
    if prod == "-1" and X % 2 != 1:
        return "NO"
    if (prod[-1] in "ijk") and (X % 4 != 2):
        return "NO"
    S = S * min(X, 5)
    prod = "1"
    i = 0
    while i < len(S) and prod != "i":
        prod = mul(prod, S[i])
        i += 1
    while i < len(S) and prod != "k":
        prod = mul(prod, S[i])
        i += 1
    if i < len(S):
        return "YES"
    else:
        return "NO"

for i in range(1, int(input()) + 1):
    print("Case #", i, ": ", solve(), sep="")

