def scoreMulti(rows, columns, width):
    total = 0
    while rows > 1:
        rows -= 1
        target = columns
        while target > 1:
            total += 1
            target -= width
    total += score(1, columns, width)
    return total

def score(rows, columns, width):
    if width == 1:
        return rows * columns
    if rows == 1:
        if columns == width:
            return columns
        else:
            total = 0
            while columns > width:
                total += 1
                columns -= width
            total += width
            return total
    else:
        return scoreMulti(rows, columns, width)
    return width

nbtests = int(raw_input())

for numtest in range(nbtests):
    rows, columns, width = map(int, raw_input().split())
    print('Case #{0}: {1}'.format(numtest + 1, score(rows, columns, width)))
