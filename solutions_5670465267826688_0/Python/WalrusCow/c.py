import sys
from functools import reduce

multDict = {
    ('i', 'j'): 'k',
    ('j', 'i'): '-k',
    ('j', 'k'): 'i',
    ('k', 'j'): '-i',
    ('i', 'k'): '-j',
    ('k', 'i'): 'j'
}

def neg(s):
    ''' Negate a string. '''
    return '-' + s if len(s) == 1 else s[1]

def mult(a, b):
    ''' Quaternion multiplication of a, b (for single strings). '''
    if a == '1': return b
    if b == '1': return a
    if a == '-1': return neg(b)
    if b == '-1': return neg(a)
    if a == b: return '-1'
    if a[0] == '-': return neg(mult(neg(a), b))
    if b[0] == '-': return neg(mult(a, neg(b)))
    return multDict[(a, b)]

def test():
    # For any s in {ijk}*, s^4 = 1
    # Thus we can take the multiple of the string modulo 12
    # (For each of i, j k in the end result)
    # Also since the result must be ijk = -1 then the string repeated (X mod 4)
    # times should multiply out to be -1 as well
    l, x = map(int, sys.stdin.readline().strip().split())
    s = sys.stdin.readline().strip()

    # Check that the string should result in -1
    product = '1'
    repeats = x % 4
    if repeats == 0: return 'NO'
    product = reduce(mult, s, '1')
    if product == '1':
        # Product of 1 is 1 repeated any number of times
        return 'NO'
    elif product == '-1':
        if x % 2 == 0:
            # Product was -1 and repeated even number of times is 1
            return 'NO'
    elif x % 4 != 2:
        # Product of i, j, k -i, -j, -k is -1 iff repeated 2 mod 4 times
        return 'NO'

    # Well now every multiple of 4 past 12 is useless
    if x > 12:
        x = 12 + x % 4

    # Idea: if we find the product is `i` at position a, then the product
    # is later `i` at position b it means that [a+1:b+1] is 1 so there
    # is no difference if that part is included in the `k` either.
    product = '1'
    searching = 'i'
    for c in s * x:
        product = mult(product, c)
        if product != 'k' and product == searching:
            if searching == 'i':
                # Start looking for j now
                searching = 'j'
                product = '1'
            elif searching == 'j':
                # Start looking for k now
                searching = 'k'
                product = '1'
    if searching == product == 'k':
        return 'YES'
    return 'NO'


def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = test()
        print('Case #{}: {}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)

