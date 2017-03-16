from fractions import gcd

pows = [1]
for i in range(50):
    pows.append(pows[-1] * 2)


def main():
    p, q = map(int, input().split('/'))
    g = gcd(p, q)
    p = p // g
    q = q // g
    if q in pows:
        k = 1
        while True:
            if p >= q // 2:
                return k
            else:
                if q == 2:
                    return k
                for i in reversed(range(len(pows))):
                    if p > pows[i]:
                        p = pows[i]
                        break
                q //= 2
                g = gcd(p, q)
                p = p // g
                q = q // g
            k += 1
    else:
        return "impossible"


if __name__ == '__main__':
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + str(main()))
