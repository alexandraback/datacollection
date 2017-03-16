def reverse_cake(s):
    ss = []
    for c in reversed(s):
        ss.append('-' if c == '+' else '+')

    return ''.join(ss)


def main():
    T = input()
    for t in range(1, T+1):
        s = raw_input()
        cnt = 0

        while '-' in s:
            idx = s.rindex('-')

            if s[0] == '-':
                cnt += 1
                s = reverse_cake(s[:idx+1]) + s[idx+1:]
            else:
                cnt += 2

                pidx = s.index('-')
                s = reverse_cake(s[pidx:idx+1]) + ('+' * pidx) + s[idx+1:]

        print "Case #%d: %d" % (t, cnt)


main()
