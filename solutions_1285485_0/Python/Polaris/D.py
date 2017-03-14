import sys

fname = 'D'

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
    H, W, D = [ int(x) for x in fp.readline().rstrip().split(' ') ]
    matrix = []
    pos_x = 0
    pos_y = 0
    for i in range(0, H):
        matrix.append(fp.readline().rstrip())
    for i in range(0, H):
        for j in range(0, W):
            if matrix[i][j] == 'X':
                pos_x = i
                pos_y = j
    dis1_x = pos_x *2 - 1
    dis2_x = (H - 1 - pos_x)*2 - 1
    xmin = min(dis1_x, dis2_x)
    xmax = max(dis1_x, dis2_x)
    gap_x = (H - 2) * 2
    x_list = [0]
    dis1_y = pos_y*2 - 1
    dis2_y = (W -1 - pos_y)*2 - 1
    ymin = min(dis1_y, dis2_y)
    ymax = max(dis1_y, dis2_y)
    gap_y = (W - 2) * 2
    y_list = [0]
    multiple = 0
    while xmin + gap_x * multiple <= D:
        x_list.extend([xmin+gap_x*multiple, -(xmax+gap_x*multiple), gap_x*(multiple+1), -(gap_x*(multiple+1))])
        multiple += 1
    multiple = 0
    while ymin + gap_y * multiple <= D:
        y_list.extend([ymin+gap_y*multiple, -(ymax+gap_y*multiple), gap_y*(multiple+1), -(gap_y*(multiple+1))])
        multiple += 1
    
    points = set()
    for x in x_list:
        if x > D:
            break
        for y in y_list:
            if x == 0 and y == 0: continue
            if x*x+y*y <= D*D :
                for point in points:
                    if point[0]*y - point[1]*x == 0 and point[0] * x >= 0 and point[1] * y >= 0:
                        break
                else:
                    points.add((x,y))
            else:
                break
    return len(points)
    
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