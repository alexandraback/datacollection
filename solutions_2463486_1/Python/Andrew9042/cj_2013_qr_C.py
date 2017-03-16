'''
Created on Apr 12, 2013

@author: Andrew
'''

sample = '''3
1 4
10 120
100 100000000000000
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

def get_fs(U):
    # Find sqrt of number
    SU = int(math.sqrt(U))
    
    if SU < 10:
        return 
    
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


def checkfs(xs):
    s = str(xs)
    for x in xrange(len(s)/2):
        if s[x] != s[len(s) - x - 1]:
            return False
    return True

def fsiter(A, B):
    sa = int(math.sqrt(A))
    sb = int(math.sqrt(B))
    
    AU = int(math.log10(sa) + 2) / 2
    AU = 10**(AU - 1)
    x = AU
    
    LU = int(math.log10(sb) + 2) / 2
    LU = 10**LU
    if LU == 1:
        LU = 10
    
    #print 'sa,sb',sa,sb
    #print 'x',x,LU
    
    count = 0
    while x <= LU:
        s = str(x)
        h = s[:len(s)-1]
        
        y =  s + ''.join(reverse(s)) 
        z = s + ''.join(reverse(h))
        
        yi = int(y)
        zi = int(z)
        
        ys = yi**2
        zs = zi**2
        if ys <= B and ys >= A and checkfs(ys):
            #print 'y',y
            count += 1
        if zs <= B and zs >= A and checkfs(zs):
            #print 'z',z
            count += 1
        #print y,z
        x += 1
    return count

def fsiter2(B):
    
    sb = int(math.sqrt(B))
    
    x = 1
    
    LU = int(math.log10(sb) + 2) / 2
    LU = 10**LU
    
    results = []
    count = 0
    while x <= LU:
        s = str(x)
        h = s[:len(s)-1]
        
        y =  s + ''.join(reverse(s)) 
        z = s + ''.join(reverse(h))
        
        yi = int(y)
        zi = int(z)
        
        ys = yi**2
        zs = zi**2
        if checkfs(ys):
            
            results.append(ys)
        if checkfs(zs):
            
            results.append(zs)
        #print y,z
        x += 1
    return results

def countfs(fs, A, B):
    x = 0
    count = 0
    while x < len(fs) and fs[x] < A:
        x += 1
    while x < len(fs) and fs[x] <= B:
        count += 1
        x += 1
    return count 

# fs = sorted(fsiter2(10**15))
# print fs
# print countfs(fs, 1, 4)
# print countfs(fs, 10, 120)
# print countfs(fs, 100, 1000)
# exit()

fs =[1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L, 100000020000001L, 100220141022001L, 102012040210201L, 102234363432201L, 121000242000121L, 121242363242121L, 123212464212321L, 123456787654321L, 400000080000004L, 10000000200000001L, 1000000002000000001L]

#for x in xrange(1,100):
#print fsiter(1,x)

#print fsiter(1,4)

#print "done"
#print get_fs(120)
#print fs(10, 120)
#exit()


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
    
    #msg = brute(A, B)
    #msg = fsiter(A,B)
    msg = countfs(fs, A, B)
    #assert msg == msg2
    printline("Case #{0}: {1}".format(case_num, msg))