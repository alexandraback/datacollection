f = open('A-small-attempt1.in', 'r')
fo = open('out_code1.out', 'w')

def last(n):
    if n==0:
        return "INSOMNIA"
    else:
        n = abs(n)
        digits = set()
        x = 1
        while True:
            a = list(str(x*n))
            b = set(a)
            digits = digits.union(b)
            if len(digits) == 10:
                return x*n
            x = x+1

a = int(f.readline())
overall = []
for i in xrange(a):
    b = int(f.readline())
    c = last(b)
    overall.append(c)
    print c

for i in xrange(1, a+1):
    output = "Case #" + str(i) + ": " + str(overall[i-1])
    fo.write(output)
    fo.write('\n')

"""
t = int(raw_input())
for i in xrange(1, t + 1):
    n = raw_input()
    last = last(n)
    print "Case #{}: {}".format(i, last)
"""
