def next_pos(pos, step, direction):
    x, y = pos
    if direction == 'E':
        return (x + step, y)
    elif direction == 'W':
        return (x - step, y)
    elif direction == 'N':
        return (x, y + step)
    elif direction == 'S':
        return (x, y - step)

directions = 'NSWE'
ops = []
result = {}
new_result = {
    (1, 0): 'E',
    (-1, 0): 'W',
    (0, 1): 'N',
    (0, -1): 'S'
}

for step in range(2, 30):
    print step
    temp_result = dict(new_result)
    new_result = dict()
    for k, v in temp_result.items():
        for d in directions:
            next = next_pos(k, step, d)
            if abs(next[0]) > 100 or abs(next[1]) > 100:
                continue
            new_result[next] = v + d
            if next not in result:
                result[next] = v + d
    print len(temp_result)

print len(result)

with open('B-small-attempt0.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for i in xrange(T):
        desire = tuple(map(int, input.pop(0).split(' ', 2)))
        f.write('Case #%d: %s\n' % (i + 1, result[desire]))

