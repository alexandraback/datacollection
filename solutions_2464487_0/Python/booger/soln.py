import math

def paint_needed(r, k):
    return 2*k*r + (2*k-1)*k

def bin_search(r, t, min_k, max_k):
    if min_k == max_k:
        return min_k
    if min_k + 1 == max_k:
        return min_k
    mid = (min_k + max_k)/2
    mid_needed = paint_needed(r, mid)
    if mid_needed < t:
        return bin_search(r, t, mid, max_k)
    if mid_needed > t:
        return bin_search(r, t, min_k, mid)
    return mid

def max_rings(r, t):
    return bin_search(r, t, 0, int(math.sqrt(t)))

def run(filename):
    lines = [line.strip() for line in open(filename).readlines() if line.strip()]
    assert int(lines[0]) == len(lines) - 1
    for i in range(1, len(lines), 1):
        (r, t) = [int(elt) for elt in lines[i].split()]
        print 'Case #%i: %i' % (i, max_rings(r, t))

run('small_input.txt')
