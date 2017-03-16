import sys
import string
import fractions
trans = string.maketrans('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')

fname = 'A'

output_format = 'single'
scale_op = input('Data Scale? 0 - sample,  1 - small,  2 - large: ')
scale = ''
if scale_op == 0: scale = 'small-practice'
elif scale_op == 1: scale = 'small'
elif scale_op == 2: scale = 'large'
else: sys.exit(0)

input_file = open(fname + '-' + scale + '.in', 'r')
output_file = open(fname + '-' + scale + '.out', 'w')


def check(line):
    #sys.stdout.write("Checking "+line+"\n")
    if "." in line: return 0
    if "X" in line and "O" in line: return 0
    if "X" in line: return "X won"
    return "O won"

def process(fp):
    (a, b) = fp.readline().rstrip().split('/')
    a = int(a)
    b = int(b)
    f = fractions.gcd(a, b)
    while f > 1:
        a = a / f
        b = b / f
        f = fractions.gcd(a, b)
    if b % 2 != 0:
        return "impossible"
    answer = 0
    for i in range(41):
        if a >= b and answer == 0:
            answer = i
        a *= 2
        if answer > 0 and (a % b) == 0:
            return answer


    return "impossible"
    print a, b
    return "What"
    answer = "Game has not completed" #ongoing
    l = fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()
    fp.readline().rstrip()
    if not "." in l: answer = "Draw" #draw
    ans = check(l[0:4])
    if ans:
        return (ans)
    ans = check(l[4:8])

    if ans:
        return (ans)
    ans = check(l[8:12])
    if ans:
        return (ans)
    ans = check(l[12:16])
    if ans:
        return (ans)

    start = 0
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 1
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 2
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 3
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    ans = check(l[0]+l[5]+l[10]+l[15])
    if ans:
        return (ans)
    ans = check(l[3]+l[6]+l[9]+l[12])
    if ans:
        return (ans)
    return (answer)
    

def format_output(fp, i, result):
    if output_format == 'single':
        fp.write('Case #%d: %s\n' % (i, result))
    elif output_format == 'multiple':
        fp.write('Case #%d:\n' % (i,))
        for r in result:
            fp.write('%s\n' % r)
    else:
        print 'No output format.'
    print('Case #%d: %s' % (i, result))

T = int(input_file.readline().rstrip('\n'))
for i in range(1, T+1):
    result = process(input_file)
    format_output(output_file, i, result)

input_file.close()
output_file.close()

print('Done.')
