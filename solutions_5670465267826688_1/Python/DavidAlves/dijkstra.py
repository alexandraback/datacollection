ONE = 1
EYE = 2
JAY = 3
KAY = 4

MUL = [
    None, # 1     i     j     k
    [None, ONE,  EYE,  JAY,  KAY], # 1
    [None, EYE, -ONE,  KAY, -JAY], # i
    [None, JAY, -KAY, -ONE,  EYE], # j
    [None, KAY,  JAY, -EYE, -ONE], # k
]

chr_to_digit = {'1': ONE, 'i': EYE, 'j': JAY, 'k': KAY}
digit_to_chr = [None, '1', 'i', 'j', 'k']


def nice(value):
    sign = '' if value > 0 else '-'
    return sign + digit_to_chr[abs(value)]


def mul(a, b):
    sign = 1 if a * b > 0 else -1
    res = MUL[abs(a)][abs(b)]
    return sign * res


def collapse(string):
    value = ONE
    for ch in string:
        value = mul(value, chr_to_digit[ch])
    return value

def total_product_is_negative_one(full_product, X):
    prod = ONE
    for i in xrange(X % 4):
        prod = mul(prod, full_product)
    return prod == -ONE


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T+1):
        L, X = map(int, raw_input().split())
        string = raw_input()

        print 'Case #{}:'.format(t),

        INFINITY = 999999999999999999999

        full_product = collapse(string)
        fp = [None] * 4
        fp[0] = ONE
        for i in xrange(1, 4):
            fp[i] = mul(fp[i-1], full_product)

        # Exit early if it can't possibly be achieved (i*j*k = -1)
        if not total_product_is_negative_one(full_product, X):
            print 'NO'
            continue

        # for given number of prefix copies, minimal # of chars to equal i
        i_magic = [INFINITY] * 4

        for prefix_count, prefix_value in enumerate(fp):
            prod = prefix_value
            for i, ch in enumerate(string):
                test = string * prefix_count + string[:i]
                if prod == EYE:
                    i_magic[prefix_count] = i
                    break
                prod = mul(prod, chr_to_digit[ch])

        # for given number of suffix copies, minimal # of chars to equal i
        k_magic = [INFINITY] * 4

        for suffix_count, suffix_value in enumerate(fp):
            prod = suffix_value
            for i, ch in enumerate(reversed(string)):
                suf = '' if i == 0 else string[-i:]
                if prod == KAY:
                    k_magic[suffix_count] = i
                    break
                prod = mul(chr_to_digit[ch], prod)

        res = False
        for pf, pc in enumerate(i_magic):
            for sf, sc in enumerate(k_magic):
                i_chars = pf * L + pc
                k_chars = sf * L + sc
                if i_chars + k_chars < L * X:
                    res = True
        print 'YES' if res else 'NO'
