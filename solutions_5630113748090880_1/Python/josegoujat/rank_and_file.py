# Read problem
no_of_cases = int(raw_input())
cases = []
for _ in range(no_of_cases):
    _n = int(raw_input())
    _pieces = []
    for __ in range(2*_n - 1):
        _pieces.append(raw_input())
    cases.append((_n, _pieces))

# Iterate cases
for i, case in enumerate(cases):
    n, pieces = case
    heights = {}
    for piece in pieces:
        for height in piece.split(' '):
            i_height = int(height)
            if i_height in heights.keys():
                heights[i_height] += 1
            else:
                heights[i_height] = 1

    missing = []
    for height, occurrences in heights.iteritems():
        if occurrences % 2 != 0:
            missing.append(height)
    missing.sort()

    str_missing = [str(e) for e in missing]

    print "Case #{}: {}".format(i+1, ' '.join(str_missing))