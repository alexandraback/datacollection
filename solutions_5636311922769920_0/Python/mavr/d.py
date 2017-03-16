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
            i = kk
            while i<kk*K+1:
                outfile.write(" %d" % i)
                i+=kk
            outfile.write("\n")