import sys

fname = 'B'

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
    input_data = [ int(x) for x in fp.readline().rstrip().split(' ') ]
    S = input_data[1]
    p = input_data[2]
    scores = input_data[3:]
    always = 0
    need_surprise = 0
    for score in scores:
        if score >= p + 2*max(0, p-1):
            always += 1
        elif score >= p + 2*max(0, p-2):
            need_surprise += 1
    return always + min(need_surprise, S)

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