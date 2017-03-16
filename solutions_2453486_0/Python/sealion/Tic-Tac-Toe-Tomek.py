import sys


def field_status(field):
    lines = field[:]
    diagonals = ['', '']
    for i in range(4):
        lines.append([line[i] for line in field])
        diagonals[0] += field[i][i]
        diagonals[1] += field[i][3 - i]
    lines += diagonals
    empty = False
    for line in lines:
        s = set(line)
        if len(s) == 1 and line[0] != '.':
            return '%s won' % line[0]
        if len(s) == 2:
            if 'T' in s:
                s.remove('T')
                c = s.pop()
                if c != '.':
                    return '%s won' % c
        if not empty and '.' in s:
            empty = True

    return 'Draw' if not empty else 'Game has not completed'


inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    field = [inp.readline().strip() for _ in range(4)]
    print 'Case #%d: %s' % (case_number, field_status(field))
    inp.readline()

