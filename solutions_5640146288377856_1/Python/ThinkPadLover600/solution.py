import fileinput


def get_cases():
    x = fileinput.input()
    x.next()
    for line in x:
        yield map(int, line.strip().split())


def solve(case):
    rows, cols, width = case
    tries = 0
    for row in range(rows):
        tries += cols / width
    for ship_hits in range(1, width):
        tries += 1
    if cols % width > 0:
        tries += 1
    return tries


if __name__ == '__main__':
    for num, case in enumerate(get_cases(), 1):
        solution = solve(case)
        print('Case #%d: %d' % (num, solution))
