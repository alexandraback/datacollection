from fractions import gcd

infile = open("A-large.in", "rU")
outfile = open("A.out", "w")

ncases = int(infile.readline())

def power_of_two(n):
    while n % 2 == 0:
        n = n / 2

    return (n == 1)

for case in xrange(1, ncases+1):
    line = infile.readline()
    
    x, y = [int(x) for x in line.strip().split("/")]
    g = gcd(x, y)
    x, y = x/g, y/g

    if not power_of_two(y):
        outfile.write("Case #%d: impossible\n" % case)
        continue

    total = 0
    while y > 2*x: #1/2 > x/y
        x *= 2
        total += 1

    outfile.write("Case #%d: %d\n" % (case, total + 1))    

infile.close()
outfile.close()
