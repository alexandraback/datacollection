#!/usr/bin/python3

from argparse import ArgumentParser
from pprint import pprint
from fractions import gcd

def debug(*args, level=1, **kwargs):
    if verbose >= level:
        print(*args, **kwargs)

def pdebug(*args, level=1, **kwargs):
    if verbose >= level:
        pprint(*args, **kwargs)

def slope(dy, dx):
    if dx or dy:
        g = abs(gcd(dx, dy))
        return (dy//g, dx//g)
    else:
        return (0, 0)

def read_map(lines, H, W):
    start = None
    assert len(lines) == H
    for r in range(H):
        line = lines[r]
        if r in (0,H-1):
            assert line == '#' * W, 'row %d: %r' % (r, line)
        else:
            assert line[0] == '#' and line[W-1] == '#' and len(line) == W
            for c in range(1,W-1):
                v = line[c]
                if v == 'X':
                    start = r-1, c-1
                elif v == '#':
                    # TODO: handle interior mirrors
                    raise NotImplementedError('interior mirrors not supported')
                else:
                    assert v == '.', 'row %d, col %d: %r' % (r, c, line)
    assert start is not None, 'start not found'
    return start


if __name__ == '__main__':
    p = ArgumentParser()
    p.add_argument('filename')
    p.add_argument('-v', '--verbose', action='count', default=0)
    p.add_argument('-n', '--limit', type=int)
    p.add_argument('-t', '--test', type=int)
    opts = p.parse_args()
    verbose = opts.verbose
    f = open(opts.filename)

    T = int(f.readline())
    if opts.limit is not None and T > opts.limit:
        T = opts.limit

    for casenum in range(1,T+1):
        H, W, D = [int(x) for x in f.readline().split()]
        layout = [[False]*W for i in range(H)]
        lines = [f.readline().rstrip('\r\n') for i in range(H)]
        if opts.test is not None and casenum != opts.test:
            continue
        try:
            start = read_map(lines, H, W)
        except (AssertionError, NotImplementedError) as e:
            print('Case #%d:'%casenum, e)
            continue

        D *= 2
        D_sq = (D//2)**2
        W = 2 * (W-2)
        H = 2 * (H-2)
        sx, sy = 2*start[1]+1, 2*start[0]+1
        debug('sx =', sx, level=1)
        debug('sy =', sy, level=1)
        debug('W =', W, level=1)
        debug('H =', H, level=1)
        debug('D =', D, level=1)
        debug('D_sq =', D_sq, level=1)

        def solve():
            count = 0
            max_x = (D // W) + 1
            max_y = (D // H) + 1
            bad = set([(0,0)])

            min_x = -max_x
            min_y = -max_y

            for x in range(min_x, max_x+1):
                dx = (x//2)*W + (x%2)*(W-sx)
                dx_sq = dx**2
                for y in range(min_y, max_y+1):
                    dy = (y//2)*H + (y%2)*(H-sy)
                    dy_sq = dy**2
                    d = dx_sq + dy_sq
                    if d <= D_sq:
                        s = slope(dx, dy)
                        if s not in bad:
                            debug('% 3d % 3d : %d' % (x, y, d))
                            count += 1
                            bad.add(s)
                        else:
                            debug('% 3d % 3d : %d (already seen)' % (x, y, d),
                                    level = 2)
                    else:
                        debug('% 3d % 3d : %d (too far)' % (x, y, d),
                                level = 3)
                    debug('                            % 3d % 3d' % (dx, dy), level=4)
            return count

        output_str = solve()
        print('Case #%d:'%casenum, output_str)
