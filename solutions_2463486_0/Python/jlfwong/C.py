import sys

squares = []
palindromes = []

# MAXB = 10 ** 14
MAXB = 1000

i = 0
while True:
    i2 = i * i
    if i2 > MAXB:
        break
    squares.append(i * i)
    i += 1

print >> sys.stderr, 'done squares', len(squares)

i = 0
while True:
    ii = int(str(i) + ''.join(reversed(str(i))))
    i1i = int(str(i) + ''.join(reversed(str(i)))[1:])
    if i1i > MAXB:
        break
    palindromes.append(ii)
    palindromes.append(i1i)
    i += 1

print >> sys.stderr, 'done palins', len(palindromes)

squares_of_palindromes = [i*i for i in palindromes]

print >> sys.stderr, 'done squares of palins', len(squares_of_palindromes)

fair_and_square = set(palindromes) & set(squares_of_palindromes)

print >> sys.stderr, 'done intersection', len(fair_and_square)

# print squares
# print palindromes
# print squares_of_palindromes
# print fair_and_square

casenum = 1
def doit(case):
    global casenum

    A, B = [int(x) for x in case.split(' ')]

    print 'Case #%d: %d' % (casenum, len([x for x in fair_and_square if A <= x <= B]))
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
