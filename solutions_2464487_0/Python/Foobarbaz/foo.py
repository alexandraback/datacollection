import fileinput,sys
import math

print_indicator = 0

def myprint(*arg):
    if print_indicator != 0:
        print print_indicator
        print arg

lines = []

for line in fileinput.input():
    lines.append(line)

n= int(lines[0])

def slow(r,t):
    which_ring = 0
    while True:
        k = which_ring*2 + 1
        paint_for_this_ring = (r+k)*(r+k) - (r+k-1)*(r+k-1)
        t =  t - paint_for_this_ring
        if (t >= 0):
            which_ring +=1
        else:
            break
    print which_ring

def fast(r,t):
    which_ring = 0
    big = 5*int(math.sqrt(t)+1)
    small = 0
    n  = 0
    myprint ("big","small", big,small)
    while big-small > 1:
        n = int((big+small)/2)
        myprint ("big","small", "n", big,small,n)
        val = 2*n*r + 2*n*(n-1) + n 
        if (val > t):
            big = n 
        else:
            small = n
    print small

case = 0
line_no =1      
myprint("n",n)
for j in xrange(1,n+1):
    case +=1
    print "Case #%d:" % (case),
    nbym = (lines[line_no]).partition(" ")
    line_no +=1
    r = int(nbym[0])
    t = int(nbym[2])
    #slow(r,t)
    fast(r,t)
