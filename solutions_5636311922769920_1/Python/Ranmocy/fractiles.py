import math

def int2str_with_base(num,b,numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and numerals[0]) or (int2str_with_base(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

def print_all(k, c):
    print k, c
    for i in range(2**k):
        s = int2str_with_base(i, 2, numerals='GL').rjust(k, 'G')
        t = list(s)
        for j in range(c-1):
            for l in range(len(t)):
                if t[l] == 'G':
                    t[l] = ['G'] * k
                else:
                    t[l] = s
            t = [item for sublist in t for item in sublist]
        print s, ''.join(t)

def pick(k, c, i, j):
    """Returns the number of array [1,k**c], which pick group i, i+1, ... , j in order."""
    print k,c,i,j
    result = 1
    for t in range(j-i+1):
        result += k**(c-t-1) * (i+t-1)
    return result

def solve(k, c, s):
    if c*s < k:
        return 'IMPOSSIBLE'
    n = int(math.ceil(1.0*k/c))
    print '{3} = {0}/{1} < {2}'.format(k,c,s,n)
    result = []
    d = 0 # distinguished group number
    for i in range(n):
        result.append(pick(k, c, min(d+1, k), min(d+c, k)))
        d += c
    return ' '.join(map(str, result))

with open('fractiles.in', 'r') as fin:
    with open('fractiles.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            K, C, S = map(int, fin.readline().split())

            # FIXME
            # print '====='
            # print_all(K,C)

            fout.write('Case #{0}: {1}\n'.format(i, solve(K, C, S)))
