f = open('a.txt', 'r')
output = open('ar.txt','w')
from fractions import gcd

n = int(f.readline())
result = []

for t in xrange(0,n):
    n = (f.readline().strip())

    s = n[0]
    for i in xrange(1, len(n)):
        print s
        if(s[0] > n[i]):
            s += n[i]
        else:
            s = n[i] + s

    result.append(s)

print result
i = 1
for r in result:
    output.write("Case #"+ str(i) + ": " + str(r) + "\n")
    i += 1
