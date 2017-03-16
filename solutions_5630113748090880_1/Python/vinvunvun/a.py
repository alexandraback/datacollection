f = open('a.txt', 'r')
output = open('ar.txt','w')
from fractions import gcd
from collections import Counter

n = int(f.readline())
result = []

for t in xrange(0,n):
    n = int(f.readline().strip())
    c = Counter()
    for i in xrange(0, (2*(n))-1):
        line = [int(x) for x in f.readline().strip().split(" ")]
        print line
        for j in line:
            c[j] += 1

    print c
    k = []
    for el in c:
        print c[el]
        if c[el] % 2 != 0:
            k.append(el)

    k = [str(x) for x in sorted(k)]
    result.append(" ".join(k))

print result
i = 1
for r in result:
    output.write("Case #"+ str(i) + ": " + str(r) + "\n")
    i += 1
