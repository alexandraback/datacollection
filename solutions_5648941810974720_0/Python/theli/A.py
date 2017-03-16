from sys import stdin

T = int(stdin.readline())

for case in xrange(1,T+1):
    s = stdin.readline().strip().lower()

    amounts    = [0] * 10
    amounts[0] = s.count('z')
    amounts[2] = s.count('w')
    amounts[4] = s.count('u')
    amounts[6] = s.count('x')
    amounts[8] = s.count('g') 

    amounts[3] = s.count('r') - amounts[4] - amounts[0]
    amounts[1] = s.count('o') - amounts[0] - amounts[4] - amounts[2]
    amounts[5] = s.count('f') - amounts[4]
    amounts[7] = s.count('v') - amounts[5]
    amounts[9] = s.count('i') - amounts[5] - amounts[6] - amounts[8]


    result = ''
    for i,a in enumerate(amounts):
        result += a * chr(48 + i)


    print 'Case #{0}: {1}'.format(case, result)

