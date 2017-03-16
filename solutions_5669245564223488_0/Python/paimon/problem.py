import sys
from string import ascii_lowercase as C

sys.stdin = open('input')
sys.stdout = open('output', 'w')

def calc(l):
    res = 1
    Left, In, Whole, Right, No, Error = range(6)

    def fact(n):
        res = 1
        for i in range(1, n + 1):
            res *= i
        return res

    def get_flag(s, c):
        if c not in s:
            return No
        e = b = s.index(c)
        while e < len(s) and s[e] == c: e += 1
        if c in s[e:]:
            return Error
        elif b == 0 and e == len(s):
            return Whole
        elif b == 0 and e < len(s):
            return Left
        elif 0 < b and e == len(s):
            return Right
        else:
            return In
        
    for c in C:
        d = {i: [] for i in range(4)}
        for i, s in enumerate(l):
            f = get_flag(s, c)
            if f in (Left, In, Whole, Right):
                d[f].append(i)
            elif f == Error:
                return 0
        if all(not x for x in d.values()):
            continue
        elif not d[In] and len(d[Left]) <= 1 and len(d[Right]) <= 1:
            res = (fact(len(d[Whole]))*res)%1000000007
            con = ''.join(l[i] for i in (d[Right] + d[Whole] + d[Left]))
            l = [s for i, s in enumerate(l) if i not in d[Right] + d[Whole] + d[Left]]
            l.append(con)
        elif len(d[In]) > 1 or (d[In] and any(d[i] for i in (Left, Whole, Right))):
            return 0

    return (res*fact(len(l)))%1000000007

t = int(input())
answer = 'Case #{0}: {1}'
for i in range(t):
    n = int(input())
    l = input().split()
    print(answer.format(i + 1, calc(l)))

sys.stdin.close()
sys.stdout.close()
