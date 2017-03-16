def flip(s):
    ss = ''
    for i in range(len(s)):
        if s[i] == '-':
            ss = '+' + ss
        else:
            ss = '-' + ss
    return ss

def main():
    T = int(input())
    for i in range(T):
        s = input()
        times = 0
        tail = len(s)
        while tail > 0:
            while tail > 0 and s[tail-1] == '+':
                tail -= 1
            if tail == 0:
                break
            if s[0] == '-':
                s = flip(s[:tail]) + s[tail:]
                times += 1
            else:
                k = 1
                while s[k] == '+':
                    k += 1
                s = flip(s[:k]) + s[k:]
                times += 1
                s = flip(s[:tail]) + s[tail:]
                times += 1
        print('Case #%d: %d' % (i + 1, times))


if __name__ == '__main__':
    main()
