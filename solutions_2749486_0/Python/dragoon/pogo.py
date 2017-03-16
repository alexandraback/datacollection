lines = open('data.txt').read()
output = open('output.txt', 'w')

lines = lines.splitlines()[1:]


def decrease_axis(x,y, start_step, steps='', insist_axis=False):
    if x == 0 and y == 0:
        if start_step == 0:
            return steps
        else:
            return False
    if start_step == 0:
        return False
    if abs(x) > abs(y):
        if x > 0:
            steps += 'E'
            return decrease_axis(x-start_step, y, start_step-1, steps)
        else:
            steps += 'W'
            return decrease_axis(x+start_step, y, start_step-1, steps)
    else:
        if y > 0:
            steps += 'N'
            return decrease_axis(x, y-start_step, start_step-1, steps)
        else:
            steps += 'S'
            return decrease_axis(x, y+start_step, start_step-1, steps)

for i, line in enumerate(lines):
    case_num = i + 1
    x, y = line.split()
    x = int(x)
    y = int(y)
    # try to minimize on each axis greedy
    i = 0
    max_range = 0
    res_arr = []
    res = False
    while True:
        if i > 500:
            break
        i += 1
        max_range += i
        if abs(x) + abs(y) > max_range:
            continue
        if x > 0:
            res = decrease_axis(x-i, y, i-1, 'E')
        else:
            res = decrease_axis(x+i, y, i-1, 'W')
        if res:
            break
    res_arr.append(res)
    res = False
    i = 0
    max_range = 0
    while True:
        if i > 500:
            break
        i += 1
        max_range += i
        if abs(x) + abs(y) > max_range:
            continue
        if y > 0:
            res = decrease_axis(x, y-i, i-1, 'N')
        else:
            res = decrease_axis(x, y+i, i-1, 'S')
        if res:
            break

    res_arr.append(res)
    res = min(res_arr, key=lambda x: len(x))
    res = ''.join(list(reversed(res)))

    output.write('Case #{0}: {1}'.format(case_num, res) + '\n')
    print 'Case #{0}: {1}'.format(case_num, res)


