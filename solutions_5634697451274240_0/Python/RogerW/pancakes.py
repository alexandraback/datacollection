def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        s = raw_input()

        s += '+'
        flipCount = 0
        for j in xrange(len(s) -1):
            if s[j] != s[j+1]:
                flipCount += 1

        print "Case #{}: {}".format(i, flipCount)

if __name__ == '__main__':
    main()
