import sys

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    A, B = map(int, f.readline().split())
    pairs = 0
    for x in range(A, B + 1):
        done = set()
        digits = str(x)
        for i in range(1, len(digits)):
            y = digits[i:] + digits[:i]
            if y[0] != '0':
                y = int(y)
                if x < y <= B and y not in done:
                    done.add(y)
                    pairs += 1

    print "Case #%d:" % (t + 1), pairs
