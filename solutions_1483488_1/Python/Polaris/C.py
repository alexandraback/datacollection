import sys

fname = 'C'

output_format = 'single'
scale_op = input('Data Scale? 0 - sample,  1 - small,  2 - large: ')
scale = ''
if scale_op == 0: scale = 'sample'
elif scale_op == 1: scale = 'small'
elif scale_op == 2: scale = 'large'
else: sys.exit(0)

input_file = open(fname + '-' + scale + '.in', 'r')
output_file = open(fname + '-' + scale + '.out', 'w')

def process(fp):
    A, B = [ int(x) for x in fp.readline().rstrip().split(' ')]
    digits = 0
    a = A
    while a != 0:
        a /= 10
        digits += 1
    multiples = 10**(digits -1)
    count = 0
    for n in range(A, B):
        original = n
        while True:
            n = n / 10 + (n % 10 * multiples)
            if n == original:
                break
            if n > original and n <= B:
                count += 1
    return count

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