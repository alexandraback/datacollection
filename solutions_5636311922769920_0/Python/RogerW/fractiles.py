def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        K, C, S = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case

        print "Case #{}:".format(i),

        if C == 1:
            if S < K:
                print "IMPOSSIBLE"
            else:   # including K == 1
                print ' '.join(str(i) for i in range(1, K+1))
        else:
            if K == 1:
                print 1
            elif S < K-1:
                print "IMPOSSIBLE"
            else:
                print ' '.join(str(i) for i in range(2, K+1))

if __name__ == '__main__':
    main()
