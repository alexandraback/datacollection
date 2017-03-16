#!/usr/bin/env python


ilines = iter(file("a.in", "r"))
#olines = iter(file("a.out", "r"))

num_lines = int(ilines.next())

def try_solve(A, sizes, changes, abort=None):
    #print "trying", A, sizes, changes
    if abort == changes:
        return abort
    while len(sizes) and sizes[0] < A:
        A += sizes.pop(0)
    if len(sizes):
        if (2*A) - 1 > sizes[0]:
            return try_solve(A, [A-1] + sizes, changes + 1, abort)
        else:
            if A > 1:
                c2 = try_solve(A, sizes[:-1], changes + 1, abort)
                c1 = try_solve(A, [A-1] + sizes, changes + 1, c2)
                return min(c1, c2)
            else:
                return changes + len(sizes)
    else:
        return changes

for l in range(num_lines):
    A, N = map(int, ilines.next().split())
    sizes = sorted(map(int, ilines.next().split()))

    changes = 0
    #print "*", A, sizes

    s = try_solve(A, sizes, 0)
    print "Case #%d: %d" %(l + 1, s)
