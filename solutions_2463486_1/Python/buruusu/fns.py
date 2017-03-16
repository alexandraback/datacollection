import math
import sys
MAX_SQRT = pow(10, 7)+1
FNS = [0]

def read_list(file):
    f = open(file, 'rb')
    for line in f.readlines():
        (s, r) = line.split()
        FNS.append(int(s))
    f.close()

def compute_list():
    r = 0
    s = 0
    while r <= MAX_SQRT:
        r += 1
        if is_palindrome(r):
            s = r*r
            if is_palindrome(s):
                FNS.append(s)
                print "%40d %20d" % (s, r)
    return s

def is_palindrome(i):
    s = str(i)
    half = len(s)/2
    for i in range(half):
        if s[i] != s[-1-i]:
            return False
    return True

def n_between(x, y):
    n = 0
    for s in FNS:
        #print 's%d x%d y%d' % (s, x, y)
        if s > y:
            return n
        elif s >= x:
            n += 1
        

def read_input():
    lines = sys.stdin.read().splitlines()
    n = int(lines[0])
    cases = list()
    for line in lines[1:]:
       a, b = line.split()
       cases.append((int(a), int(b)))
    return cases

case = 1
def output_case(outcome):
    global case
    print 'Case #%d: %s' % (case, outcome)
    case += 1 
    
#compute_list()
read_list('fns.txt')
cases = read_input()
for c in cases:
    output_case(str(n_between(c[0], c[1])))


    
#for f in FNS:
#    print f
    
