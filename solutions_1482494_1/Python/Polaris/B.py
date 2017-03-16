import sys
import string


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
    not_complete = []
    one_complete = []
    levels = int(fp.readline().rstrip())
    for i in range(0, levels):
        not_complete.append(tuple([ int(x) for x in fp.readline().rstrip().split(' ') ]))

    power = 0
    count = 0
    not_complete.sort(key=lambda x: x[1], reverse=True)
    while len(not_complete) > 0 or len(one_complete) > 0:
        flag = 0
        if len(not_complete) > 0 and power >= not_complete[-1][1]:
            not_complete.remove(not_complete[-1])
            power += 2
            flag = 1

        if flag == 0:
            for i in range(0, len(one_complete)):
                if power >= one_complete[i]:
                    one_complete.remove(one_complete[i])
                    power += 1
                    flag = 1
                    break
        if flag == 0:
            for i in range(0, len(not_complete)):
                if power >= not_complete[i][0]:
                    one_complete.append(not_complete[i][1])
                    not_complete.remove(not_complete[i])
                    power += 1
                    flag = 1
                    break
        if flag == 0:
            return "Too Bad"
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
