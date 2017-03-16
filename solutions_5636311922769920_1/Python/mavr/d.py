import sys

input_filename = sys.argv[1]

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        t = infile.readline()
        t = 0
        for line in infile:
            t+=1
            K, C, S = map(int, line.split())
            kk = K**(C-1)
            outfile.write("Case #%d:" % t)
            if S*C<K:
                outfile.write(" IMPOSSIBLE\n")
                continue
            i = 0
            for w in xrange(S):
                s = []
                n = 0
                for j in xrange(C):
                    print n, i
                    n = n*K+i
                    print n
                    i = min(i+1, K-1)
                outfile.write(" %d" % (n+1))
                if n+1==K**C: break
            outfile.write("\n")