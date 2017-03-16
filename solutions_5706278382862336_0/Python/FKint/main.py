import sys

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
def minus(a, b):
    tmp = (a[0]*b[1]-a[1], a[1]*b[1])
    g = gcd(tmp[0], tmp[1])
    return (tmp[0]/g, tmp[1]/g)
def larger(a, b):
    return a[0]*b[1]>=b[0]*a[1]

lines = sys.stdin.readlines()
T = int(lines[0])
for current_case in range(1, T+1):
    P, Q = [int(i) for i in lines[current_case].split('/')]
    #print P, Q
    current_num = (P, Q)
    first = -1
    for i in range(1, 41):
        p = (1, 2**i)
        if larger(current_num, p):
            current_num = minus(current_num, p)
            if first == -1:
                first = i
    if first == -1 or current_num[0] != 0:
        print "Case #"+str(current_case)+": impossible"
    else:
        print "Case #"+str(current_case)+": "+str(first)


