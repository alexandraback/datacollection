import random
import sys
import sympy

print("Case #{}:".format(1))

T = int(input())
n, kol = map(int, input().split())

def simpleComposite(n):
    for i in range(2, 30):
        if n%i == 0:
            return i
    return None

def interpret(s, B):
    val = 0
    for i in range(n):
        val = val*B + int(s[i])
    return val
    

S = set()
while len(S) < kol:
    s = '1' + ''.join([random.choice('01') for _ in range(n-2)]) + '1'
    ok = True

    for B in range(2, 11):
        if simpleComposite(interpret(s, B)) is None:
            ok = False
            break

    if ok:
        S.add(s)
        print("len(S) = {}".format(len(S)), file=sys.stderr)

for s in S:
    out = [s]
    for B in range(2, 11):
        x = simpleComposite(interpret(s, B))
        out.append(str(x))
    print(" ".join(out))
    print(" ".join(out), file=sys.stderr)
