import sys
import itertools

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            l, x = map(int, f.readline().split())
            s = f.readline().strip()
            yield case, (l, x, s)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def is_neg(a):
    return len(a) == 2

def neg(a):
    if is_neg(a):
        return a[1]
    else:
        return '-'+a

i = 'i'
j = 'j'
k = 'k'
def m(a, b):
    if a == '1':
        return b
    if b == '1':
        return a
    if is_neg(a) and is_neg(b):
        return m(a[1],b[1])
    if is_neg(a) :
        return neg(m(a[1], b))
    if is_neg(b):
        return neg(m(a, b[1]))
    if a == b:
        return '-1'
    if a == i and b == j:
        return k
    if a == i and b == k:
        return '-j'
    if a == j and b == i:
        return '-k'
    if a == j and b == k:
        return i
    if a == k and b == i:
        return j
    if a == k and b == j:
        return '-i'
    print 'EERROR', a, b

def power(b, exp):
    out = '1'
    for _ in xrange(exp % 4):
        out = m(out, b)
    return out

TARGET_VALUE = '-1'
def problem(l, x, s):
    value = '1'
    for q in s:
        value = m(value, q)
    value = power(value, x)
    if value != TARGET_VALUE:
        return "NO"

    found = False
    value = '1'
    for ind, q in enumerate(itertools.chain(*itertools.repeat(s, min(x,4)))):
        value = m(value, q)
        if value == i:
            found = True
            i_pos = ind
            break
    if not found:
        return "NO"

    total_len = len(s)*x 
    value = '1'
    for ind, q in enumerate(itertools.chain(*itertools.repeat(s[::-1], min(x,4)))):
        if ind >= total_len - i_pos - 2:
            break
        value = m(q, value)
        if value == k:
            return "YES"
    return "NO"

def evaluate(s, x=1):
    value = '1'
    for q in s:
        value = m(value, q)
    value = power(value, x)
    return value

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

