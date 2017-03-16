#!/usr/bin/env python

layouts = {}

def gen_layout(r, c):
    if c == 0:
        yield []
        return
    for x in xrange(r + 1):
        for sub in gen_layout(r - x, c - 1):
            yield [x] + [x + z for z in sub]

def validate_layout(r, c, layout):
    if layout[0] == r:
        return False
    #print 'val', r, c, layout
    z = []
    for i in xrange(c):
        cc = layout[max(i-1, 0):i+2]
        #print 'val z', i, cc
        m = max(cc)
        if m == 0:
            z.append(r)
        else:
            z.append(max(r - m - 1, 0))
    #print 'val z', z
    op = []
    for i in xrange(c):
        cc = z[max(i-1, 0):i+2]
        #print 'val op', i, cc
        m = max(cc)
        if m == 0:
            op.append(0)
        else:
            op.append(min(m + 1, r))
    #print 'val op', op
    op[0] = max(op[0], 1)
    #print 'val op', op
    return all(o + l == r for o, l in zip(op, layout))


def gen_layouts(r, c):
    mem = {}
    for layout in gen_layout(r, c):
        #print 'gen', r, c, layout
        m = sum(layout)
        if m in mem:
            continue
        if validate_layout(r, c, layout):
            mem[m] = layout
    layouts[r, c] = mem

def print_layout(r, c, layout):
    return [''.join('c' if (i, j) == (0, 0) else '.' if i < r - layout[j] else '*'
            for j in xrange(c))
        for i in xrange(r)]

def solve():
    r, c, m = map(int, raw_input().strip().split())
    if r > 5 or c > 5:
        return ['Impossibru!']
    if (r, c) not in layouts:
        gen_layouts(r, c)
    ans = layouts[r, c].get(m)
    if not ans:
        return ['Impossible']
    return print_layout(r, c, ans)


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i)
        for line in ret:
            print line

if __name__ == '__main__':
    main()
