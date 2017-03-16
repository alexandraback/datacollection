from fractions import Fraction
f = open('A-small-attempt1.in')
# f = open('test.in')
count = int(f.readline())
output = ''
for x in range(1,count + 1):
    line = f.readline()
    fraction = Fraction(line)
    P = fraction.numerator
    Q = fraction.denominator

    if Q%2 != 0:
        output += 'Case #' + str(x) + ': impossible\n'
    else:
        min = 0
        tmp = 0
        while Q%2 == 0:
            Q = Q/2
            tmp += 1
            if Q <= P and min == 0:
                min = tmp
        if Q == 1:
            output += 'Case #' + str(x) + ': ' + str(min) + '\n'
        else:
            output += 'Case #' + str(x) + ': impossible\n'

print(output)
newf = open('output.txt','w')
newf.write(output)
