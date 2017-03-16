def flip(s):
    ss = ''
    for i in range(len(s)):
        if s[i] == '-':
            ss = '+' + ss
        else:
            ss = '-' + ss
    return ss

def main():
    with open('b.in') as ifile:
        with open('b.out', 'w') as ofile:
            T = int(ifile.readline().strip())
            for i in range(T):
                s = ifile.readline().strip()
                print(s)
                times = 0
                tail = len(s)
                while tail > 0:
                    while tail > 0 and s[tail-1] == '+':
                        tail -= 1
                    if tail == 0:
                        break
                    if s[0] == '-':
                        s = flip(s[:tail]) + s[tail:]
                        print(s)
                        times += 1
                    else:
                        k = 1
                        while s[k] == '+':
                            k += 1
                        s = flip(s[:k]) + s[k:]
                        print(s)
                        times += 1
                        s = flip(s[:tail]) + s[tail:]
                        print(s)
                        times += 1
                ofile.write('Case #%d: %d\n' % (i + 1, times))


if __name__ == '__main__':
    main()
