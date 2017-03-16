def read_an_int(stream):
    return int(stream.readline())

def read_ints(stream):
    return map(int, stream.readline().split())

def read_string(stream):
    return stream.readline().strip()


"""
Numbers are represented as a tuple of coefficient (1 or -1) and unit (1, 'i', 'j' or 'k').

Let the given substring be L, and the whole string (L*x) be S, to determine if possible to
split S into required parts.
1. S should reduce to the same number as ijk, i.e. -1.
2. Given property #1, we only need to choose a prefix of S that reduces to i, and posfix of S
that reduces to k, (and the two parts are overlapped), then the remaining part will reduce to j.
3. A prefix of S can be represented as (N, x), which means if contains N copies of L, plus
the substring L[:x], and we only need to consider cases N < 4, since a**4 = 1 for any number a.
"""
table = {('1', '1'): (1, '1'),
         ('1', 'i'): (1, 'i'),
         ('1', 'j'): (1, 'j'),
         ('1', 'k'): (1, 'k'),
         ('i', '1'): (1, 'i'),
         ('i', 'i'): (-1, '1'),
         ('i', 'j'): (1, 'k'),
         ('i', 'k'): (-1, 'j'),
         ('j', '1'): (1, 'j'),
         ('j', 'i'): (-1, 'k'),
         ('j', 'j'): (-1, '1'),
         ('j', 'k'): (1, 'i'),
         ('k', '1'): (1, 'k'),
         ('k', 'i'): (1, 'j'),
         ('k', 'j'): (-1, 'i'),
         ('k', 'k'): (-1, '1')}

def multiple(x, y):
    co = x[0]*y[0]
    co2, unit = table[(x[1], y[1])]
    return (co*co2, unit)

def power(x, n):
    n = n % 4
    if n == 0:
        return (1, '1')
    if n == 1:
        return x
    if n == 2:
        return multiple(x, x)
    if n == 3:
        return multiple(multiple(x, x), x)
    
    
def prefix_product_index(s):
    """
    Create a hashtable H that if H[(co, u)] = n, then s[:n] is the shortest
    prefix if s that reduces to (co, u).
    As a side product, will also return the product of the whole string.
    """
    result = {(1, '1'): -1}
    current_product = (1, '1')
    for i, c in enumerate(s):
        current_product = multiple(current_product, (1, c))
        if current_product not in result:
            result[current_product] = i
    return result, current_product

def postfix_product_index(s):
    l = len(s)
    result = {(1, '1'): l}
    current_product = (1, '1')
    for i, c in enumerate(s[::-1]):
        current_product = multiple((1, c), current_product)
        if current_product not in result:
            result[current_product] = l - i - 1
    return result

def solve(s, X):
    left_index, prod = prefix_product_index(s)
    right_index = postfix_product_index(s)
    if power(prod, X) != (-1, '1'):
        return "NO"
    # find a prefix (leftN, leftx) that reduces to i
    leftN = 0
    leftx = None
    while leftN < min(4, X):
        needed_prefix = multiple(power(prod, 4 - leftN), (1, 'i'))
        if needed_prefix in left_index:
            leftx = left_index[needed_prefix]
            break
        else:
            leftN += 1
    # find a postfix that reduces to k``
    rightN = 0
    rightx = None
    while rightN < min(4, X):
        needed_postfix = multiple((1, 'k'), power(prod, 4-rightN))
        if needed_postfix in right_index:
            rightx = right_index[needed_postfix]
            break
        else:
            rightN += 1
    # if both parts are found and they don't overlap
    if leftx != None and rightx != None and (
            ((leftN + rightN) < X-1) or ((leftN + rightN) == X-1 and (leftx < rightx-1))):
        return "YES"
    else:
        return "NO"

def main():
    from sys import argv
    ifile = argv[1]
    ofile = ifile.rsplit('.', 1)[0] + '.out'
    with open(ofile, 'w') as ostr:
        with open(ifile, 'r') as istr:
            T = read_an_int(istr)
            for case in range(T):
                L, X = read_ints(istr)
                template = read_string(istr)
                if len(template) != L:
                    print "Error!!!"
                solution = solve(template, X)
                ostr.write("Case #%d: %s\n" % (case+1, str(solution)))
main()
 
