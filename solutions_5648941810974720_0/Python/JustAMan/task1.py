import sys

FIRST = [
('ZERO', 'Z', 0),
('TWO', 'W', 2),
('FOUR', 'U', 4),
('SIX', 'X', 6),
('EIGHT', 'G', 8),
]

SECOND = [
('ONE', 'O', 1),
('THREE', 'T', 3),
('FIVE', 'F', 5),
('SEVEN', 'S', 7),
]


def solve(s):
    digs = []
    for data in (FIRST, SECOND):
        for (name, ch, val) in data:
            amount = s.count(ch)
            if amount > 0:
                digs.extend([val] * amount)
                for ch in name:
                    s = s.replace(ch, '', amount)
    amount = len(s) / 4
    if amount > 0:
        digs.extend([9] * amount)
    return ''.join(str(x) for x in sorted(digs))

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            s = inp.readline().strip()
            out.write('Case #%d: %s\n' % (t + 1, solve(s)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
