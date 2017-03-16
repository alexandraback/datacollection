def area(r, n):
    return 2 * r * (n + 1) + 2 * n * (n + 1) + n + 1

def main():
    n = int(raw_input())
    for tt in range(n):
        r, t = map(int, raw_input().split())

        i = 0
        j = 2 * (10 ** 18) + 1
        while(i + 1 != j):
            k = (i + j) / 2
            if (area(r, k) <= t):
                i = k
            else:
                j = k

        print("Case #{}: {}".format(tt + 1, i + 1))

if __name__ == "__main__":
    main()

