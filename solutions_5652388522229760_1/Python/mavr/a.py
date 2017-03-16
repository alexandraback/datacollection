import sys

input_filename = sys.argv[1]

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        T = infile.readline()
        tests = map(int, infile.read().splitlines())
        for t, n in enumerate(tests):
            if n==0:
                outfile.write("Case #%d: INSOMNIA\n" % (t+1))
                continue
            seen = set()
            nn = n
            for i in xrange(1, 1000):
                for c in str(nn):
                    seen.add(c)
                if len(seen)==10:
                    break
                nn += n
            outfile.write("Case #%d: %d\n" % (t+1, nn))