input = open('input', 'r')
output = open('output', 'w')

from fractions import gcd

def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)


def simplify(a,b):
    d = gcd(a,b)
    return a/d, b/d

def find_x(p,q):
    for i in xrange(0,40):
        term = 2**(i+1)*p-q
        if term >= 0 and term % 2 == 0:
            return i+1

testcases = int(input.readline().strip())
for testcase in xrange(1, testcases+1):
    fract = input.readline().strip().split('/')
    p1, q1 = (int(x) for x in fract)
    p , q = simplify(p1, q1)
    if not is_power2(q):
        output.write("Case #%s: %s\n" % (testcase, "impossible"))
        continue
    x = find_x(p,q)
    if x == None:
        output.write("Case #%s: %s\n" % (testcase, "impossible"))
    output.write("Case #%s: %d\n" % (testcase, x))


input.close()
output.close()
