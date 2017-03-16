
num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
    n = int(raw_input())
    lines = [ list(map(int, raw_input().split())) for r in range(2 * n - 1) ]

    value_indices = {}
    for line in lines:
        for ix, value in enumerate(line):
            if value not in value_indices:
                value_indices[value] = []
            value_indices[value].append(ix)

    missing = []
    for value, indices in value_indices.items():
        if len(indices) % 2 == 0:
            continue
        missing.append(value)
    missing.sort()
    if len(missing) != n:
        print('*** aaargggh! panic!!! ***')

    result = ' '.join(map(str, missing))
    print('Case #%d: %s' % (case_index, result))
