import math
import itertools

_dbg = 0


# search maximume integer'x' keeping 'func(x)' true.
def _find_mx(func, x=0, step=1):
    while True:
        assert func(x)
        nx = x + step
        if func(nx):
            x = nx
            step += step
        elif 1 == step:
            return x
        else:
            step /= 2
            

def stupid_s(e, n):
    cx = 0
    cy = 0
    step = 1
    p = []
    if cx < e:
        d = e - cx
        for i in xrange(d):
            p.append('WE')
    elif cx > e:
        d = cx - e
        for i in xrange(d):
            p.append('EW')
    if cy < n:
        d = n - cy
        for i in xrange(d):
            p.append('SN')
    elif cy > n:
        d = cy - n
        for i in xrange(d):
            p.append('NS')

    return ''.join(p)
    

def solve(case, in_lines):
    out = 'Case #%d: '%case
 
    if _dbg:
        for line in in_lines:
            print line
            
    e, n = [int(x) for x in in_lines[0].split()]

    return out + stupid_s(e, n)


def main(raw):
    lines = raw.split('\n')
    n = int(lines[0])
    ln = 1
    outs = []
    for case in xrange(1, n+1):
        buff = []
        endln = ln + 1
        while ln < endln and lines[ln]:
            buff.append(lines[ln])
            ln += 1
        s = solve(case, buff)
        print s
        outs.append(s)
    return '\n'.join(outs)
    pass

if __name__ == '__main__':
    test_input = """2
3 4
-3 4"""
    force_no_file = 0
    in_file_name = '' if force_no_file else 'B-small-attempt0.in'
    base_path = 'G:/workspace/py/codejam2013/R1C/'
    if in_file_name:
        with open(base_path + in_file_name) as f:
            raw = f.read()
    else:
        raw = test_input
    out = main(raw)
    if in_file_name:
        with open(base_path + in_file_name + '.out', 'w') as f:
            f.write(out)
    pass