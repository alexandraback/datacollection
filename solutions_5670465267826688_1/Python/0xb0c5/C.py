def to_quat(c):
    return (1, '1ijk'.index(c))

def quat_mul((a_sign, a_val), (b_sign, b_val)):
    if a_val == 0: # 1
        return (a_sign*b_sign, b_val)
    if b_val == 0:
        return (a_sign*b_sign, a_val)
    if a_val == b_val:
        return (-1*a_sign*b_sign, 0)
    if a_val == 1: # i
        if b_val == 2: # i * j
            return (a_sign * b_sign, 3)
        if b_val == 3: # i * k
            return (-1 * a_sign * b_sign, 2)
    if a_val == 2: # j
        if b_val == 1: # j * i
            return (-1 * a_sign * b_sign, 3)
        if b_val == 3: # j * k
            return (a_sign * b_sign, 1)
    if a_val == 3: # k
        if b_val == 1: # k * i
            return (a_sign * b_sign, 2)
        if b_val == 2: # k * j
            return (-1 * a_sign * b_sign, 1)

def quat_pow(q,n):
    p = (1,0)
    # anything ^ 4 = 1
    for _ in range(n%4):
        p = quat_mul(p,q)
    return p
            
def solve2(s,l,x, fast=1):
    # calculate the total product, must be -1
    prod = (1,0)
    for c in s:
        q = to_quat(c)
        prod = quat_mul(prod,q)
    if quat_pow(prod, x) != (-1, 0):
        return "NO" # - product isn't -1
    
    remain = [(1,3),(1,1),(1,0)]
    cur = (1,0)
    prev_change = None
    if x > 8:
        x = 8
    for x_i in xrange(x):
        if not remain:
            break
        for l_i in xrange(l):
            # if we've searched 4 full cycles, we won't find anything new
            if fast:
                if (x_i-4,l_i) == prev_change:
                    return "NO" # 4 cycles without finding
                
            if cur == remain[-1]:
                remain.pop()
                prev_change = (x_i,l_i)
                if not remain:
                    break
                
            cur = quat_mul(cur, to_quat(s[l_i]))
            
    if remain:
        return "NO" # finished searching string without finding"
        
    return "YES"

n_cases = input()

for i in range(1,n_cases+1):
    l,x = map(int,raw_input().split(' '))
    s = raw_input()
    print "Case #%d: %s" % (i, solve2(s,l,x,1))
 