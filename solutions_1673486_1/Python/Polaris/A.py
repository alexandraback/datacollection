import sys
import string


fname = 'A'

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
    typed, whole = [ int(x) for x in fp.readline().rstrip().split(' ') ]
    left = whole - typed
    prob_list = [ float(x) for x in fp.readline().rstrip().split(' ') ]
    correct = [1.0, ]
    all_correct = 1.0
    for prob in prob_list:
        all_correct *= prob
        correct.append(all_correct)
    result_list = []
    keep_typing = correct[-1]*(left+1)+(1-correct[-1])*(left+whole+2)
    result_list.append(keep_typing)
    for i in range(1, typed+1):
        back_type = correct[-1-i]*(2*i+left+1)+(1-correct[-1-i])*(2*i+left+whole+2)
        result_list.append(back_type)
    right_away = 2+whole
    result_list.append(right_away)
    return "%.6f" %float(min(result_list))
    

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
