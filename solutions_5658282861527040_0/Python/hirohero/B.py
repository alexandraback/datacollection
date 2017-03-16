import math

f = open('B-small-attempt0.in','r').readlines()
fout = open('B-small-attempt0.out','w')

test = int(f[0].strip())

for ttest in range(test):
    a, b, k = f[ttest + 1].strip().split()
    a, b, k = int(a), int(b), int(k)
    dem = 0

    for i in range(a):
        for j in range(b):
            if (i & j) < k:
                dem += 1
    s = "Case #" + str(ttest + 1) + ": " + str(dem)
    print >> fout, s
fout.close()
