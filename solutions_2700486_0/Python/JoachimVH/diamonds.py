'''
Created on 4-mei-2013

@author: Joachim
'''

"""
pyramid sides (excluding top): 0, 2, 4, 6, etc.
both sides need to be filled before we can start on the next one
sides (+top):
    0,0
    0,2; -2,0; 2,0; -1,1; 1,1
    ...
==> all blocks on (x,y) with abs(x)+y == 2*i
    or: i = (abs(x)+y)/2 (CHECK %2)
number of blocks needed to fill previous sides:
    1 + 5 + 9 + 13 + ... + (i-1)*4+1
    = i + sum(x=0..(i-1), 4*x)
    = i + 2 * (i-1) * i
subtract this from N
if < 0 ==> P = 0
else:
P(y==0) = 
    N=1: .5
    N=2: .75 (1-.5^2)
    note: changes to 100% when entire side is filled
    N=2*i+1: 1
P(y==1) = 
    N=1: 0
    N=2: .25
    ...
P(y==2) = 
    N=3: .5^3
L blocks left, R blocks right
if N < height: P(L=z) == .5^z+.5^(N-z)
"""

def faculty(x, end):
    if x <= end:
        return x
    else:
        return x * faculty(x-1, end)

def combination(x, n):
    if x == n:
        return 1
    z1 = max(x, n-x)
    z2 = min(x, n-x)
    return 1.0*faculty(n, z1+1)/faculty(z2, 1)

def get_side(x, y):
    return (abs(x)+y)/2

def get_previous_sizes(side):
    return side + 2 * (side - 1) * side

def handle_case(n, x, y):
    if (abs(x) + y) % 2 == 1:
        return 0
    side = get_side(x, y)
    n -= get_previous_sizes(side)
    if n < 0:
        return 0
    max_side = 2*side
    if n > max_side + y:
        return 1
    if n > max_side:
        y -= n - max_side
        n -= 2*(n-max_side)
        
    return 1.0*sum(combination(z, n) for z in xrange(y+1, n+1))/(2**n)

f = open(r"c:/Temp/input.txt", "r")
cases = int(f.readline())
out = open("c:/Temp/output.txt", "w")
for i in xrange(1, cases+1):
    print i
    n, x, y = [int(z) for z in f.readline().strip().split()]
    out.write("Case #%d: %.6f\n" % (i, handle_case(n, x, y)))
f.close()
out.close()