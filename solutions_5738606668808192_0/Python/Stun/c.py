import math
import random

def convert(repr, base):
    ret = 0
    for i in range(0, len(repr)):
        ret *= base
        if (repr[i] == '1'):
            ret += 1
    return ret

def divisor(num):
    sq = int(math.sqrt(num))
    for i in range(2, sq+1):
        if num % i == 0: return i
    return 0

def solve(repr):
    ret = []
    for base in range(2, 11):
        num = convert(repr, base)
        d = divisor(num)
        if d == 0:
            return ret
        ret.append(d)
    return ret
    
def generator(N):
    repr = "1"
    for i in range(0, N-2):
        if random.random() > 0.5:
            digit = "1"
        else:
            digit = "0"
        repr += digit
    repr += "1"
    return repr
    
seen = {}
def getNext(N):
    repr = generator(N)
    if repr in seen: return getNext(N)
    seen[repr] = True
    return repr
    
N = 16
J = 50

print "Case #1:"

for i in range(0, J):
    ok = False
    while not ok:
        repr = getNext(N)
        elem = solve(repr);
        if len(elem) == 9:
            print repr,
            for e in elem:
                print e,
            print
            ok = True