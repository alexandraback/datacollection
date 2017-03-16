def signature(s):
    result = []
    currentChar = ''
    subtotal = 0
    for c in s:
        if c != currentChar:
            result.append([c, 1])
            currentChar = c
        else:
            result[-1][1] += 1
    return result

def merge_sig(leading, end):
    if leading == []:
        return end[0]
    elif end == []:
        return leading[0]
    else:
        result = leading[0]
        result.extend(end[0][1:])
        return result

def factorial(n):
    i = 1
    for j in range(1, n+1):
        i = (i*j)%1000000007
    return i
    
def connect(sigs, c):
    leading, middle, whole, end = [], [], [], []
    for sig in sigs[:]:
        if len(sig) == 1:
            # sig has only one char
            if sig[0][0] == c:
                whole.append(sig)
        else:
            # more than one part
            if sig[0][0] == c:
                end.append(sig)
            if sig[-1][0] == c:
                leading.append(sig)
            for part in sig[1:-1]:
                if part[0] == c:
                    middle.append(sig)
    part_total = len(leading) + len(middle) + len(whole) + len(end)
    if len(middle) > 0:
        if part_total > 1:
            return 0, []
        else:
            return 1, sigs
    elif part_total == 0:
        return 1, sigs
    else:
        if len(leading) > 1 or len(end) > 1:
            # more than 1 leading or ending, means impossible
            return 0, []
        elif len(leading) == 0 and len(end) == 0:
###            print "whole: ", whole
            for sig in whole:
                sigs.remove(sig)
            sigs.append(whole[0])
            return factorial(len(whole)), sigs
        else:
            if leading != [] and end != [] and leading[0] is end[0]:
                return 0, []
            allparts = leading + whole + end
            for sig in allparts:
                sigs.remove(sig)
            sigs.append(merge_sig(leading, end))
            return factorial(len(whole)), sigs
            
import string
def solve(sarray):
    signatures = map(signature, sarray)
    total = 1
    for c in string.lowercase:
        n, signatures = connect(signatures, c)
#        print n, signatures
        total = (total*n)%1000000007
        if total == 0:
            return 0
    total = (total*factorial(len(signatures)))%1000000007
    return total

from sys import stdin
readline = stdin.readline
C = int(readline())
for cas in range(C):
    T = int(readline())
    strings  = readline().split()
    print "Case #%d: %d" % (cas+1, solve(strings))
