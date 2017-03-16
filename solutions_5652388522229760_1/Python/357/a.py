def main():
    T = int(input())
    for i in range(T):
        n = int(input())
        if n == 0:
            print('Case #%d: INSOMNIA' % (i + 1))
        else:
            k = 1
            f = [0] * 10
            while True:
                x = k * n
                while x > 0:
                    f[x % 10] = 1
                    x //= 10
                if all(f):
                    print('Case #%d: %d' % (i + 1, k * n))
                    break
                k += 1


if __name__ == "__main__":
    main()
