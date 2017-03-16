import random

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

P = 4711930799906184953162487834760260422020574773409675520188634839616415335845034221205289256705544681972439104097777157991804380284218315038719444943990492579030720635990538452312528339864352999310398481791730017201031090

def check_base(s, base):
    val = 0
    for c in s:
        val = val * base + int(c)
    d = gcd(val, P)
    if d == 1:
        return 1
    e = 2
    while val % e != 0:
        e += 1
    if 1 < e < val and val % e == 0:
        return e
    else:
        return 1

n = 32
j = 500

ans_set = set()
print("Case #1:")
while len(ans_set) != j:
    s = [1] + [random.randint(0, 1) for i in range(n -2)] + [1]
    s = "".join(map(str, s))
    if s in ans_set:
        continue
    div_str = ""
    for base in range(2, 11):
        d = check_base(s, base)
        if d == 1:
            div_str = ""
            break
        else:
            div_str += " " + str(d)
    if div_str:
        print(s + div_str)
        ans_set.add(s)

