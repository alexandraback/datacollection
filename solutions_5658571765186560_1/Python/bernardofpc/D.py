def solve(x,r,c):
    if x >= 7: return 'RICHARD'              # Hole on the domino

    if (r*c) % x != 0: return 'RICHARD'      # Tiling arithmetic
    if r < x and c < x : return 'RICHARD'    # Fit a 1-by-x x-omino
    if min(r,c) < (x+1)//2: return 'RICHARD' # Contain a rectangle for every possible x-omino

    if x == 1: return 'GABRIEL'
    if x == 2: return 'GABRIEL' # The modulus condition is out of the way.
    if x == 3: return 'GABRIEL' # One side is divisible by 3, so is large enough.
    if x == 4:
        if min(r,c) == 2: return 'RICHARD'  # T cannot fit (odd)
        else: return 'GABRIEL'
    if x == 5:
        if min(r,c) == 3 and max(r,c) == 5: return 'RICHARD' # Can't fit "\\"
        else: return 'GABRIEL'
    if x == 6:
        if min(r,c) == 3: return 'RICHARD'  # Cannot fit _|^^ (4x3)
        else: return 'GABRIEL'


import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    li = sys.stdin.readline()
    [x, r, c] = [int(x) for x in li.split()]

    ans = solve(x,r,c)

    print('Case #{}: {}'.format(icase, ans))
    #print('Case #{} ({}, {}x{}): {}'.format(icase, x, r, c, ans))

