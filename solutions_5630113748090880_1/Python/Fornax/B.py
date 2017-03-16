#!/usr/bin/python3

from collections import defaultdict

from codejam import CodeJam

def docase(f):
    n = int(f.readline())
    groups = []
    for i in range(2*n-1):
        groups.append([int(_) for _ in f.readline().split()])
    heights = defaultdict(int)
    for group in groups:
        for soldier in group:
            heights[soldier] += 1
    missing = []
    for height in heights:
        if heights[height] % 2 != 0:
            missing.append(height)
    return ' '.join(str(h) for h in sorted(missing))

cj = CodeJam(docase)

# After importing cj into an interactive terminal, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
