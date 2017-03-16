def solve(rows):
    m = {}
    for row in rows:
        for col in row:
            if col in m:
                m[col] += 1
            else:
                m[col] = 1

    missing = []

    for (key, val) in m.items():
        if val % 2 == 1:
            missing.append(int(key))

    missing.sort()

    return ' '.join(str(x) for x in missing)

file = open('input2b')

cases_count = int(file.readline().strip())

index = 1

while True:
    line = file.readline()

    if not line or line.isspace():
        break

    size = int(line)
    items = []

    for i in range(2 * size - 1):
        items.append(file.readline().strip().split())

    answer = solve(items)

    print('Case #%d: %s' % (index, answer))
    index += 1

file.close()
