def is_continue(conditions):
    #print conditions
    return any(c[1] > 0 for c in conditions)


def is_attacked(walls, w, e, s):
    for block in (w, e):
        if walls[block] < s:
            return True
    return False


def set_wall(walls, w, e, s):
    for block in (w, e):
        walls[block] = s

with open('C-small-attempt0.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for i in xrange(T):
        N = int(input.pop(0))
        conditions = [map(int, input.pop(0).split(' ', 8)) for n in range(N)]
        walls = {n: 0 for n in range(-500, 501)}
        attacks = 0
        day = -1
        while is_continue(conditions):
            day += 1
            #print 'day ' + str(day)
            set_walls = []
            for c in conditions:
                if day == c[0]:
                    # start attacking
                    w, e, s = c[2:5]
                    if is_attacked(walls, w, e, s):
                        #print w, e, s
                        attacks += 1
                        set_walls.append([w, e, s])
                    c[1] -= 1     # number -1
                    if c[1] > 0:
                        c[0] += c[5]  # next day
                    c[4] += c[7]  # next s
                    c[2] += c[6]  # next w
                    c[3] += c[6]  # next e
            sorted(set_walls, key=lambda x: x[2])
            for set_w in set_walls:
                set_wall(walls, *set_w)

        print 'Case #%d: %d\n' % (i + 1, attacks)
        f.write('Case #%d: %d\n' % (i + 1, attacks))
