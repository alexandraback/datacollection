#!/usr/bin/env python

layouts = {}

def gen_layout(r, c):
    if c == 0:
        yield []
        return
    for x in xrange(r + 1):
        for sub in gen_layout(r - x, c - 1):
            yield [x] + [x + z for z in sub]

def gen_layout2(r, c):
    for i in xrange(r):
        for j in xrange(c):
            base = [r - i - 1 if x <= j else r for x in xrange(c)]
            yield base
            for ii in xrange(1, i + 1):
                for jj in xrange(1, j + 1):
                    sub = [0 if x < jj else 1 for x in xrange(j)] + [i - ii + 1]
                    yield [a + b for a, b in zip(base, sub + [0] * (c - j - 1))]

def gen_layout3(r, c, m):
    for i in xrange(r):
        for j in xrange(c):
            a = r * c - (i + 1) * (j + 1)
            b = r * c - i * j
            if not a <= m < b:
                continue
            base = [r - i - 1 if x <= j else r for x in xrange(c)]
            if a == m:
                yield base
            for ii in xrange(1, i + 1):
                jj = a + (i - ii) + 1 + j - m
                if 1 <= jj <= j:
                    sub = [0 if x < jj else 1 for x in xrange(j)] + [i - ii + 1]
                    yield [a + b for a, b in zip(base, sub + [0] * (c - j - 1))]


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
    for layout in gen_layout2(r, c):
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

def get_layout(r, c, m):
    if (r, c) not in layouts:
        gen_layouts(r, c)
    return layouts[r, c].get(m)


def get_layout2(r, c, m):
    for layout in gen_layout3(r, c, m):
        if sum(layout) != m:
            continue
        if validate_layout(r, c, layout):
            return layout
    return None


def solve():
    r, c, m = map(int, raw_input().strip().split())
    ans = get_layout2(r, c, m)
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
