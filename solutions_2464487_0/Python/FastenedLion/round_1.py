from math import pi, sqrt, floor
from test.test_decorators import memoize

@memoize
def helper(i):
    return str(i)

def decide_bad(line):
    r, t = line.split()
    t = int(t)
    r = int(r)
    y = 0
    amount = 0
    c = 2*r-3    
    while amount <= t:
        y += 1
        amount += c+4*y
    y-=1
    print y
    return str(y)


def decide(line):
    r, t = line.split()
    t = int(t)
    r = int(r)
    y = int((sqrt(4* (r**2) - 4*r + 8*t +1) -2*r +1)/4)
    print y
    used = 2*r - 3 + 2*y*(y+1)
#    if used > t:
#        y-=1
#        print "too much"
    return y
            
filename = 'input.in'
f = open(filename)
o = open('solution.out', 'w')

n = int(f.readline().strip())
print n, "Cases"
count = 1
results = map(decide, f.readlines())
sols = []
for result in results:
    sols.append("Case #" + str(count) + ": " + str(result))
    count += 1
f.close()
o.write('\n'.join(sols))
o.close()
