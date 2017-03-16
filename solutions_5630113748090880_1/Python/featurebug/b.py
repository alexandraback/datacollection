import collections

INPUT = 'B-large.in'

with open(INPUT) as f:
    lines = f.read().split('\n')

cases = int(lines[0])
i = 0
for c in range(1, cases+1):
    i += 1
    n = int(lines[i])
    counts = collections.defaultdict(lambda: 0)
    for _ in range(2*n-1):
        i += 1
        for height in lines[i].split(' '):
            counts[int(height)] += 1
    # Odd values are missing
    missing = []
    for height, count in counts.items():
        if count % 2 == 1:
            missing.append(height)
    missing = [str(x) for x in sorted(missing)]
    print('Case #{0}: {1}'.format(c, ' '.join(missing)))