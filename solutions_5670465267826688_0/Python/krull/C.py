import math
Q = { '1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
      'i': {'1': 'i', 'i':'-1', 'j': 'k', 'k': '-j'},
      'j': { '1': 'j', 'i': '-k', 'j':'-1', 'k': 'i'},
      'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}}
def Product(x, y):
    xp = x[0]
    yp = y[0]
    xsign = 1
    ysign = 1
    if len(x) == 2:
        xsign = -1
        xp = x[1]
    if len(y) == 2:
        ysign == -1
        yp = y[1]
    prod_sign = xsign * ysign
    #print xp, yp, Q[xp][yp]
    if len(Q[xp][yp]) == 2:
        result_sign = -1
        prod = Q[xp][yp][1]
    else:
        result_sign = 1
        prod = Q[xp][yp][0]
    result_sign = result_sign * prod_sign
    if result_sign < 0:
        prod = '-' + prod
    return prod 

def CASE(in1, in2):
    #print in1, in2
    chk_list = ['i', 'j', 'k']
    chk_flag = [0, 0, 0]
    chk_index = 0
    L, X = map(int, in1.split())
    cstr = in2
    prod = '1'
    for p in range(L*X):
        q = p % L
        prod = Product(prod, cstr[q])
        #print prod
        if prod == chk_list[chk_index]:
            #print prod
            #print q
            if chk_index < 2:
                chk_flag[chk_index] = 1
                chk_index += 1
                prod = '1'
            else:
                chk_flag[chk_index] = 1
        else:
            chk_flag[chk_index] = 0
    #print chk_flag
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
