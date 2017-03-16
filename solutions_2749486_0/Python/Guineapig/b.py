dirs = [(0, 1, 'N'), (0, -1, 'S'), (1, 0, 'E'), (-1, 0, 'W')]

def solve(x, y, max_x, max_y):
    ps = [(0, 0, '')]
    l = 1
    while True:
        reached_pos = set()
        new_ps = []
        for px, py, path in ps:
            for dx, dy, o in dirs:
                nx = px + l * dx
                ny = py + l * dy
                new_path = path + o
                if nx == x and ny == y:
                    return new_path
                if nx <= max_x and ny <= max_y and (nx, ny) not in reached_pos:
                    new_ps.append((nx, ny, new_path))
                    reached_pos.add((nx, ny))
        ps = new_ps
        l += 1


##############################################################################

def read_ints(f):
    s = f.readline()
    return [int(w) for w in s.strip().split()]


from sys import argv

in_fn = argv[1]
out_fn = len(argv) > 2 and argv[2] or in_fn + '.out'

in_f = open(in_fn)
out_f = open(out_fn, 'w')

T = int(in_f.readline().strip())

for i_t in range(T):
    x, y = read_ints(in_f)
    # cache = {}
    res = solve(x, y, 100, 100)
    out_ln =  'Case #%d: %s' % (i_t+1, res)
    print >> out_f, out_ln
    print out_ln



