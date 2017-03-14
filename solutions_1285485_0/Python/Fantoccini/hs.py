'''
Created on Apr 14, 2012

@author: Fantoccini
'''

def gcd(a, b):
    if b == 0: return a
    if b > a: return gcd(b, a)
    return gcd(b, a % b)

def dis(a, b, u, d, l, r, s):
    aa = a
    bb = b
    if a > 0:
        dx = 2 * r
    else:
        dx = 2 * l
        a = -a
    if b > 0:
        dy = 2 * d
    else:
        dy = 2 * u
        b = -b
    x = (a / 2) * (2 * (r + l)) + (a % 2) * dx
    y = (b / 2) * (2 * (u + d)) + (b % 2) * dy
    if x * x + y * y > dd * dd:
        return False
    g = gcd(x, y)
    x /= g
    y /= g
    if aa < 0:
        x = -x
    if bb < 0:
        y = -y
    if (x, y) in s:
        return False
    s.add((x, y))
    return True

fin = open("h.in", "r")
fout = open("hs.out", "w")
t = int (fin.readline())
m = [0 for col in range(31)]
for i in range(t):
    m = [0 for col in range(31)]
    l = fin.readline()
    l = l.strip()
    nums = l.split()
    h = int(nums[0])
    w = int(nums[1])    
    dd = int(nums[2])
    c = 0
    xl = 0
    xu = 0    
    for j in range(h):
        m[j] = fin.readline().strip()
        if m[j].find('X') >= 0:
            xu = j - 0.5 
            xl = m[j].find('X') - 0.5
    xd = h - 2 - xu;
    xr = w - 2 - xl;
    s = set()
    for a in range(dd + 1):
        for b in range(a, dd + 1):
            if a + b == 0:
                continue 
            if a * a + b * b > dd * dd:
                break
            if dis(a, b, xu, xd, xl, xr, s):
                c += 1
                    #print a, b
            if dis(b, a, xu, xd, xl, xr, s):
                c += 1
                #print b, a
            if a > 0: 
                if dis(-a, b, xu, xd, xl, xr, s):
                    c += 1
                    #print -a, b
                if dis(b, -a, xu, xd, xl, xr, s) :
                    c += 1
                    #print b, -a
            if b > 0: 
                if dis(a, -b, xu, xd, xl, xr, s):
                    c += 1
                    #print a, -b
                if dis(-b, a, xu, xd, xl, xr, s):
                    c += 1
                    #print -b, a
            if a > 0 and b > 0: 
                if dis(-a, -b, xu, xd, xl, xr, s):
                    c += 1
                    #print -a, -b
                if dis(-b, -a, xu, xd, xl, xr, s):
                    c += 1
                    #print -b, -a
    fout.write("Case #" + str (i + 1) + ": " + str(c) + "\n")
    print "case", i
fin.close()
fout.close()
