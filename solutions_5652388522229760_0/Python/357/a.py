def main():
    with open('a.in') as ifile:
        with open('a.out', 'w') as ofile:
            T = int(ifile.readline().strip())
            for i in range(T):
                n = int(ifile.readline().strip())
                if n == 0:
                    ofile.write('Case #%d: INSOMNIA\n' % (i + 1))
                else:
                    k = 1
                    f = [0] * 10
                    while True:
                        x = k * n
                        while x > 0:
                            f[x % 10] = 1
                            x //= 10
                        if all(f):
                            ofile.write('Case #%d: %d\n' % (i + 1, k * n))
                            break
                        k += 1


if __name__ == "__main__":
    main()
