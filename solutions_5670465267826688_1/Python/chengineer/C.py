import sys

def multiply(a, b):
    # a, b in the form of (sign, value)
    # sign from (-1, 1)
    # value from ('1', 'i', 'j', 'k')
    sign = a[0] * b[0]
    m = a[1]
    n = b[1]
    if m == '1':
        value = n
    elif n == '1':
        value = m
    elif m == n:
        value = '1'
        sign *= -1
    elif m == 'i' and n == 'j':
        value = 'k'
    elif m == 'i' and n == 'k':
        value = 'j'
        sign *= -1
    elif m == 'j' and n == 'i':
        value = 'k'
        sign *= -1
    elif m == 'j' and n == 'k':
        value = 'i'
    elif m == 'k' and n == 'i':
        value = 'j'
    elif m == 'k' and n == 'j':
        value = 'i'
        sign *= -1
    return (sign, value)

def reduce(s, result = (1, '1')):
    # multiply the characters in a string and return (sign, value)
    while s != '':
        if s[0] != '-':
            result = multiply(result, (1, s[0]))
            s = s[1:]
        else:
            # s[0] == '-'
            result = multiply(result, (-1, s[1]))
            s = s[2:]
    return result

def reduce_dup(a, n):
    # reduce a in form of (sign, value) n times
    sign = a[0]
    value = a[1]
    if value == '1':
        if n % 2 == 1:
            new_sign = sign
            new_value = '1'
        else:
            new_sign = 1
            new_value = '1'
    else:
        if n % 4 == 1:
            new_sign = sign
            new_value = value
        elif n % 4 == 2:
            new_sign = -1
            new_value = '1'
        elif n % 4 == 3:
            new_sign = sign * -1
            new_value = value
        elif n % 4 == 0:
            new_sign = 1
            new_value = '1'
    return (new_sign, new_value)

def answer(l, x, s):
    if len(s) != l:
        print 'Error: %d %d %s' % (l, x, s)
    # i * j * k = -1
    reduction = reduce(s)
    if reduce_dup(reduction, x) != (-1, '1'):
        return 'NO'
    # cycles after 8 repeats, 4 for head (i) and 4 for tail (k)
    if x > 8:
        x = 8
    s = s * x
    l = len(s)
    pos_dict = {}
    rpos_dict = {}
    for sign in (-1, 1):
        for value in ('1', 'i', 'j', 'k'):
            pos_dict[(sign, value)] = []
    for sign in (-1, 1):
        for value in ('1', 'i', 'j', 'k'):
            rpos_dict[(sign, value)] = []
    substring1 = (1, '1')
    substring2 = (1, '1')
    for idx1 in range(l):
        substring1 = multiply(substring1, (1, s[idx1]))
        pos_dict[substring1].append(idx1)
    for idx2 in range(l-1, -1, -1):
        substring2 = multiply((1, s[idx2]), substring2)
        rpos_dict[substring2].append(idx2)
    for pos in pos_dict[(1, 'i')]:
        for rpos in rpos_dict[(1, 'k')]:
            if pos <= rpos:
                return 'YES'
    return 'NO'

if __name__ == '__main__':
    f = sys.stdin
    fn = sys.argv[1]
    f = open(fn)
    if len(sys.argv) == 3:
        output = open(sys.argv[2], 'w')

    t = int(f.readline())
    for _t in xrange(t):
        [l, x] = map(int, f.readline().split())
        s = f.readline().strip()
        ans = answer(l, x, s)
        if len(sys.argv) == 3:
            output.write('Case #%d: %s' % (_t+1, ans) + '\n')
        print 'Case #%d: %s' % (_t+1, ans)