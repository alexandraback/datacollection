import sys

def solve(L, X, line):
    line_product = quaternions_products(line)
    total_product = quaternions_power(line_product, X)

    if total_product != '-1':
        return False

    i_power, i_offset = find_closest_i(L, X, line_product, line)
    k_power, k_offset = find_closest_k(L, X, line_product, line)
    if i_power is None or k_power is None:
        return False

    #print 'i:', i_power, i_offset
    #print 'k:', k_power, k_offset

    required_power = i_power + k_power
    if i_offset != -1:
        required_power += 1
        if k_offset != -1 and i_offset >= k_offset - 1:
            required_power += 1
    elif k_offset != -1:
        required_power += 1

    return required_power <= X


def find_closest_i(L, X, line_product, line):
    closest_positions = {}
    r = '1'
    for i, x in enumerate(line):
        r = quaternions_product(r, x)
        if r not in closest_positions:
            closest_positions[r] = i
    if 'i' in closest_positions:
        return 0, closest_positions['i']
    else:
        if line_product == '1':
            return None, None
        if line_product == '-1':
            x = closest_positions.get('-i')
            if x is None:
                return None, None
            else:
                return 1, x
        else:
            for power in range(1, 4):
                prefix = quaternions_power(line_product, power)
                if prefix == 'i':
                    return power, -1
                missing = get_right_multiplier(prefix, 'i')
                x = closest_positions.get(missing)
                if x is not None:
                    return power, x
    return None, None


def find_closest_k(L, X, line_product, line):
    closest_positions = {}
    r = '1'
    for i, x in enumerate(reversed(line)):
        r = quaternions_product(x, r)
        if r not in closest_positions:
            closest_positions[r] = L - 1 - i

    if 'k' in closest_positions:
        return 0, closest_positions['k']
    else:
        if line_product == '1':
            return None, None
        if line_product == '-1':
            x = closest_positions.get('-k')
            if x is None:
                return None, None
            else:
                return 1, x
        else:
            for power in range(1, 4):
                prefix = quaternions_power(line_product, power)
                if prefix == 'k':
                    return power, -1
                missing = get_left_multiplier(prefix, 'k')
                x = closest_positions.get(missing)
                if x is not None:
                    return power, x
    return None, None


def quaternions_products(line):
    r = '1'
    for x in line:
        r = quaternions_product(r, x)

    return r


def quaternions_power(a, power):
    if a == '1':
        return a
    if a == '-1':
        return a if power % 2 else '1'

    power = power % 4
    if power == 0:
        return '1'
    elif power == 1:
        return a
    elif power == 2:
        return '-1'
    else:
        return quaternions_product('-1', a)


PRODUCT_MAP = {
    ('1', '1'): '1',
    ('1', 'i'): 'i',
    ('1', 'j'): 'j',
    ('1', 'k'): 'k',
    ('i', '1'): 'i',
    ('i', 'i'): '-1',
    ('i', 'j'): 'k',
    ('i', 'k'): '-j',
    ('j', '1'): 'j',
    ('j', 'i'): '-k',
    ('j', 'j'): '-1',
    ('j', 'k'): 'i',
    ('k', '1'): 'k',
    ('k', 'i'): 'j',
    ('k', 'j'): '-i',
    ('k', 'k'): '-1',
}

for (a, b), c in PRODUCT_MAP.items():
    if c.startswith('-'):
        minusc = c[1]
    else:
        minusc = '-' + c

    PRODUCT_MAP[('-' + a, '-' + b)] = c
    PRODUCT_MAP[(a, '-' + b)] = minusc
    PRODUCT_MAP[('-' + a, b)] = minusc


LEFT_MULTIPLIERS = dict(
    ((b, c), a)
    for (a, b), c in PRODUCT_MAP.iteritems())

RIGHT_MULTIPLIERS = dict(
    ((a, c), b)
    for (a, b), c in PRODUCT_MAP.iteritems())

def get_right_multiplier(left, product):
    return RIGHT_MULTIPLIERS[(left, product)]


def get_left_multiplier(right, product):
    return LEFT_MULTIPLIERS[(right, product)]

def quaternions_product(a, b):
    sign = 1
    if a.startswith('-'):
        a = a[1]
        sign *= -1
    if b.startswith('-'):
        b = b[1]
        sign *= -1

    result = PRODUCT_MAP[(a, b)]
    if result.startswith('-'):
        result = result[1]
        sign *= -1

    return result if sign > 0 else '-' + result


def read_ints():
    return map(int, sys.stdin.readline().split(' '))

if __name__ == '__main__':
    t, = read_ints()
    for i in range(t):
        L, X = read_ints()
        line = sys.stdin.readline().strip()
        print 'Case #%d: %s' % (i + 1, 'YES' if solve(L, X, line) else 'NO')
