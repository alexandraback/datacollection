def main():
    a, b, k = map(int, input().split())
    res = 0
    for x in range(a):
        for y in range(b):
            if x & y < k:
                res += 1
    return str(res)


if __name__ == '__main__':
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + main())
