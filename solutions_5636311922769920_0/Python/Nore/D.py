
def ev(l, k):
    u = 0
    for x in l:
        u = k * u + x
    return u

def r(k, c, s):
    if s * c < k: return "IMPOSSIBLE"
    w = []
    for i in range((k - 1) // c + 1):
        u = ev([(c * i + j) % k for j in range(c)], k)
        w.append(u + 1)
    return " ".join(str(x) for x in w)

t = int(input())
for i in range(t):
    k, c, s = map(int, input().split())
    print("Case #" + str(i + 1) + ":", end = " ")
    print(r(k, c, s))

    