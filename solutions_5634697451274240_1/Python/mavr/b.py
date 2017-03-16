import sys

input_filename = sys.argv[1]

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        t = infile.readline()
        for t, line in enumerate(infile):
            line = line.strip()+"+"
            ans = 0
            for i in xrange(len(line)-1):
                if line[i]!=line[i+1]:
                    ans+=1
            outfile.write("Case #%d: %d\n" % (t+1, ans))