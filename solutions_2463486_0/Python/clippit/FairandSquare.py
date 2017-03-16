import math

with open('C-small-attempt0.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for t in xrange(T):
        A, B = map(long, input.pop(0).split(' ', 2))
        count = 0
        for n in xrange(A, B + 1):
            strn = str(n)
            if strn == ''.join(reversed(strn)):
                sqrt = math.sqrt(n)
                if (sqrt == long(sqrt)):
                    ssqrt = str(long(sqrt))
                    if ssqrt == ''.join(reversed(ssqrt)):
                        count += 1
        f.write('Case #%d: %d\n' % (t + 1, count))
