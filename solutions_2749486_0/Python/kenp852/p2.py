import sys

num_cases = int(sys.stdin.readline())

def get_closer_n(s):
    n_lower = int((2 * s + 0.25)**0.5 - 0.5)
    n_higher = n_lower + 1
    s_lower = n_lower * (n_lower + 1) / 2
    s_higher = n_higher * (n_higher + 1) / 2
    if s < s_lower or s > s_higher:
        raise Exception('something went wrong')
    lower_better = (s - s_lower) <= (s_higher - s)
    n = n_lower if lower_better else n_higher
    return (n, lower_better)

def get_n(target, lower_better):
    n = int((2 * target + 0.25)**0.5 - 0.5)
    return n if lower_better else n+1

def get_jumps(X, Y):
    jumps = ''
    
    x, y = abs(X), abs(Y)
    s = x + y
    n, lower_better = get_closer_n(s)
    
    n_x = get_n(x, lower_better)
    l_x = n_x * (n_x + 1) / 2
    d_x = l_x - x
    
    n_y = n - n_x
    l_y = n * (n + 1) / 2 - l_x
    d_y = l_y - y
    
    x_dir = 'E' if X > 0 else 'W'
    x_swap = 'WE' if (X > 0) ^ (d_x > 0) else 'EW'
    
    y_dir = 'N' if Y > 0 else 'S'
    y_swap = 'SN' if (Y > 0) ^ (d_y > 0) else 'NS'

    jumps += (x_dir * n_x) + (y_dir * n_y)

    jumps += (x_swap * abs(d_x)) + (y_swap * abs(d_y))
    
    return jumps

for j in xrange(num_cases):
    X, Y = [int(e) for e in sys.stdin.readline().strip().split()]

    print "Case #%s: %s" % (j+1, get_jumps(X, Y))
    j += 1

