d = [100000000000000000 for _ in range(10000000)]
d[1] = 1

for i in range(1, 1000000):
    d[i + 1] = min(d[i + 1], d[i] + 1)
    r = int(str(i)[::-1])
    d[r] = min(d[r], d[i] + 1)


def main():
    x = int(input())
    return d[x]


if __name__ == '__main__':
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + str(main()))
