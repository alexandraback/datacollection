import sys

args = sys.argv
file = args[1]
f = open(file)

cases = int(f.readline())

def minToPTen(n):
    if n == 0:
        return 1
    elif n == 1:
        return 10
    else:
        b = n /2
        e = n - b
        return minToPTen(n - 1) + 10**b + 10**e - 1

def minCount2(n):
    if n <= 20:
        return n
    s = str(n)
    if s[-1] == '0':
        return minCount2(n - 1) + 1
    l = len(s)
    if l % 2 == 0:
        sb = s[:l/2][-1::-1]
        ic = 0
        se = s[l/2:]
    else:
        sb = s[:l/2][-1::-1]
        sc = s[l/2]
        ic = int(sc)*(10**(l/2))
        se = s[l/2 + 1:]
    PT = minToPTen(l - 1)
    #print PT
    #print s
    #print sb
    #print se
    #print ic
    if int(sb) == 1:
        return PT + int(se) + ic
    elif int(se) == 1:
        return PT + int(sb) + ic + 1
    else:
        return PT + int(sb) + int(se) + ic

for i in range(cases):
    n = int(f.readline())
    print "Case #%s: %s" % (i + 1,minCount2(n))
    
