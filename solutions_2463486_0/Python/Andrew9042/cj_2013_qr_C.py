'''
Created on Apr 12, 2013

@author: Andrew
'''

sample = '''3
1 4
10 120
100 1000
'''.split('\n')

sample_o = '''Case #1: 2
Case #2: 0
Case #3: 2'''.split('\n')

def raw_input_test():
    global sample
    if len(sample) == 0:
        return ''
    ret = sample[0]
    sample = sample[1:]
    return ret

def _print(x):
    print x

def print_test(x):
    global sample_o
    s = sample_o[0]
    #if s != x: print "ERROR"
    sample_o = sample_o[1:]
    print x

getline = raw_input
printline = _print

#getline = raw_input_test
#printline = print_test

import math

def reverse(x):
    x = [y for y in x]
    x.reverse()
    return x
'''
def get_fs(U):
    # Find sqrt of number
    SU = int(math.sqrt(U))
    
    if SU < 10:
        return SU
    
    # Now find how many fair numbers are below SU
    N = int(math.log10(SU)) + 1 # digits in SU
    
    
    digits = map(int, list(str(SU)))
    
    left = digits[:(len(digits) + 1) / 2]
    right = digits[(len(digits) + 1) / 2:]
    ls = int(''.join(map(str,left)))
    rs = int(''.join(map(str,right)))
    print left,right
    print ls,rs
    
    candofirst = left[-1] <= right[0]
    remaining = ls - 1
    if candofirst:
        remaining += 1
     
    restoftens = 10**((N - 1) / 2) * 9
    
    result = remaining + restoftens
    
    return result

def fs(A, B):
    return get_fs(B) - get_fs(A - 1)

print get_fs(120)
print fs(10, 120)
exit()
'''

def isapal(xs):
    s = str(xs).replace('L','')
    ispal = True
    for y in range(len(s) / 2):
        if s[y] != s[(y+1)*-1]:
            ispal = False
            break
    return ispal 
def brute(A, B):
    sa = int(math.sqrt(A))
    sb = int(math.sqrt(B))
    
    numfs = 0
    for x in xrange(sa, sb+1):
        xs = x**2
        if xs < A:
            continue
        
        if isapal(x) and isapal(xs):
            numfs += 1
            #print x,xs
    return numfs


num_cases = int(getline())

for case_num in xrange(1,num_cases + 1):
    A, B = map(int, getline().strip().split(' '))
    #print A,B
    msg = brute(A, B)
    printline("Case #{0}: {1}".format(case_num, msg))