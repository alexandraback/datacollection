import math
Q = { '1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
      'i': {'1': 'i', 'i':'-1', 'j': 'k', 'k': '-j'},
      'j': { '1': 'j', 'i': '-k', 'j':'-1', 'k': 'i'},
      'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}}
def Product(x, y):
    #print "len-x, len-y : ", len(x), len(y)
    xp = x[0]
    yp = y[0]
    xsign = 1
    ysign = 1
    if len(x) == 2:
        xsign = -1
        xp = x[1]
    if len(y) == 2:
        ysign = -1
        yp = y[1]
    #print "x-sign, y-sign: ", xsign, ysign
    prod_sign = xsign * ysign
    #print xp, yp, Q[xp][yp]
    if len(Q[xp][yp]) == 2:
        result_sign = -1
        prod = Q[xp][yp][1]
    else:
        result_sign = 1
        prod = Q[xp][yp][0]
    #print "prod_sign, result_sign = ", prod_sign, result_sign
    result_sign = result_sign * prod_sign
    if result_sign < 0:
        prod = '-' + prod
    return prod 

def UnitProduct(cstr):
    prod = '1'
    p = 0
    N = len(cstr)
    while p < N:
        prod = Product(prod, cstr[p])
        p += 1
    return prod

def CalcLeft(cstr, L):
    s = ''
    for i in range(4):
        s += cstr
    cstr = s
    prod = '1'
    q = 0
    found_left = False
    left_length = 0
    remaining_cstr_left = cstr
    N = 4 * L
    while q < N:
        prod = Product(prod, cstr[q])
        if prod == 'i':
            found_left = True
            left_length = q + 1
            remaining_cstr_left = cstr[left_length:]
            return (found_left, left_length, remaining_cstr_left)
        q += 1
    return (found_left, left_length, remaining_cstr_left)

def CalcRight(cstr, L):
    s = ''
    for i in range(4):
        s += cstr
    cstr = s
    prod = '1'
    found_right = False
    right_length = 0
    remaining_cstr_right = cstr
    N = 4 * L
    q = N - 1
    while q >= 0:
        #print "prod right inputs =  ", cstr[q], prod
        prod = Product(cstr[q], prod)
        #print "prod right result = ", prod
        if prod == 'k':
            found_right = True
            right_length = N - q 
            remaining_cstr_right = cstr[:q]
            return (found_right, right_length, remaining_cstr_right)
        q -= 1
    return (found_right, right_length, remaining_cstr_right)

 
def BigCase(L, X, cstr):
    unit_element = UnitProduct(cstr)
    found_left, left_length, remaining_cstr_left = CalcLeft(cstr, L)
    if not found_left:
        #print "i not found in BigCase"
        return 'NO'
    found_right, right_length, remaining_cstr_right = CalcRight(cstr, L)
    if not found_right:
        #print "k not found in BigCase"
        return 'NO'
    mult = (X - 8) % 4
    central_element = '1'
    for i in range(mult):
        central_element = Product(central_element, unit_element)
    
    mid_element = Product(UnitProduct(remaining_cstr_left), central_element)
    mid_element = Product(mid_element, UnitProduct(remaining_cstr_right))
    if mid_element == 'j':
        return 'YES'
    else:
        return 'NO'

def CASE(in1, in2):
    ##print in1, in2
    chk_list = ['i', 'j', 'k']
    chk_flag = [0, 0, 0]
    chk_index = 0
    L, X = map(int, in1.split())
    cstr = in2
    if X > 8:
        result = BigCase(L, X, cstr)
        return result
    prod = '1'
    N = L * X
    p = 0
    while p < N:
        q = p % L
        prod = Product(prod, cstr[q])
        ##print prod
        if prod == chk_list[chk_index]:
            ##print prod
            ##print q
            if chk_index < 2:
                chk_flag[chk_index] = 1
                chk_index += 1
                prod = '1'
            else:
                chk_flag[chk_index] = 1
        else:
            chk_flag[chk_index] = 0
        p += 1
    ##print chk_flag
    for elem in chk_flag:
        if elem == 0:
            return 'NO'
    return 'YES'   
 
def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        in1 = IN.readline().strip() 
        in2 = IN.readline().strip()
        OUT.write("Case #%i: %s\n" % (i, CASE(in1, in2)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
