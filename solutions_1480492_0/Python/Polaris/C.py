import sys
import string


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

def f_eq(a, b):
    if abs(a-b) <= 0.0000001:
        return True
    else:
        return False

def process(fp):
    T = 0.0
    cars = int(fp.readline().rstrip())
    left_lane = []
    right_lane = []
    for i in range(0, cars):
        t = fp.readline().rstrip().split(' ')
        if t[0] == 'L':
            left_lane.append([int(t[1]), float(t[2])])
        elif t[0] == 'R':
            right_lane.append([int(t[1]), float(t[2])])
    left_lane.sort(key=lambda x: x[1], reverse=True)
    right_lane.sort(key=lambda x: x[1], reverse=True)
    rd = 1
    while True:
        t_list = []
        for i in range(0, len(left_lane)-1):
            if left_lane[i+1][0] > left_lane[i][0]:
                t_list.append((left_lane[i][1]-left_lane[i+1][1]-5)*1.0 / (left_lane[i+1][0]-left_lane[i][0]))
        for i in range(0, len(right_lane)-1):
            if right_lane[i+1][0] > right_lane[i][0]:
                t_list.append((right_lane[i][1]-right_lane[i+1][1]-5)*1.0 / (right_lane[i+1][0]-right_lane[i][0]))
        if len(t_list) == 0:
            return 'Possible'
        min_t = min(t_list)
        if f_eq(min_t, 0) and rd != 1:
            return T

        T += min_t
        for car in left_lane:
            car[1] += car[0] * min_t
        for car in right_lane:
            car[1] += car[0] * min_t
        left_can = []
        right_can = []
        while True:
            for i in range(1, len(left_lane)):
                if f_eq(left_lane[i-1][1] - left_lane[i][1], 5):
                    right_can.append(left_lane[i])
                    left_lane.remove(left_lane[i])
                    break
            else:
                break

        for car in right_can:
            seq = [ abs(car[1] - other[1]) for other in right_lane ]
            if len(seq) != 0 and min(seq) < 4.9999999:
                return T
            
        while True:
            for i in range(1, len(right_lane)):
                if f_eq(right_lane[i-1][1] - right_lane[i][1], 5):
                    left_can.append(right_lane[i])
                    right_lane.remove(right_lane[i])
                    break
            else:
                break
        
        left_lane.extend(left_can)
        right_lane.extend(right_can)
            
        left_lane.sort(key=lambda x: x[1], reverse=True)
        for i in range(0, len(left_lane)-1):
            if left_lane[i][1] - left_lane[i+1][1] < 4.9999999:
                return T
        right_lane.sort(key=lambda x: x[1], reverse=True)
        for i in range(0, len(right_lane)-1):
            if right_lane[i][1] - right_lane[i+1][1] < 4.9999999:
                return T
                
        
        rd += 1

                
    
                

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
