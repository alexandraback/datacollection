
I = 'i'
J = 'j'
K = 'k'
TABLE = {
    (1, 1): ( 1, 1),
    (1, I): ( 1, I),
    (1, J): ( 1, J),
    (1, K): ( 1, K),
    
    (I, 1): ( 1, I),
    (I, I): (-1, 1),
    (I, J): ( 1, K),
    (I, K): (-1, J),

    (J, 1): ( 1, J),
    (J, I): (-1, K),
    (J, J): (-1, 1),
    (J, K): ( 1, I),

    (K, 1): ( 1, K),
    (K, I): ( 1, J),
    (K, J): (-1, I),
    (K, K): (-1, 1),
}

def mult(q1, q2):
    s1, b1 = q1
    s2, b2 = q2
    s, b = TABLE[(b1, b2)]
    return (s * s1 * s2, b)


def is_total_ok(line, X):
    product = (1, 1)
    for x in line:
        product = mult(product, (1, x))
    sign, base = product
    if base == 1:
        return (sign == -1) and (X % 2 != 0)
    else:
        return (X % 2 == 0) and (X % 4 != 0)


def mult_until(line, q0):
    product = (1, 1)
    if product == q0:
        return 0
    for pos, x in enumerate(line):
        product = mult(product, (1, x))
        if product == q0:
            return (pos + 1)
    return None


def solve(line, X):
    #print line, X
    if not is_total_ok(line, X):
        #print 'Boo'
        return False
    total_len = X * len(line)
    line_x_4 = line * 4
    pos1 = mult_until(line_x_4, (1, I))
    if pos1 is None or pos1 > total_len:
        return False
    #print pos1
    pos2 = mult_until(line_x_4[pos1:] + line_x_4, (1, J))
    if pos2 is None or (pos1 + pos2) > total_len:
        return False
    #print pos2 + pos1
    return True


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
         L, X = map(int, raw_input().split())
         line = raw_input()
         print "Case #{0}:".format(t + 1), "YES" if solve(line, X) else "NO"
