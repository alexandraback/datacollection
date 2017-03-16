f = open('B-small-attempt0.in', 'r')
fo = open('out_code2_small.out', 'w')

def flip(n):
    a = list(n)
    a.append('+')
    counter = 0
    for i in xrange(len(a)-1):
        if a[i] != a[i+1]:
            counter += 1
    return counter

a = int(f.readline())
overall = []
for i in xrange(a):
    b = f.readline().strip()
    c = flip(b)
    overall.append(c)
    print c

for i in xrange(1, a+1):
    output = "Case #" + str(i) + ": " + str(overall[i-1])
    fo.write(output)
    fo.write('\n')

