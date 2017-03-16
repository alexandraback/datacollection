from collections import namedtuple

Test = namedtuple('Test', 'S')

def read(line):
    return Test(*line.split())

def solve(test):
    indices = range(1, 1 + len(test.S))
    status = {tuple(): tuple(side == '+' for side in test.S)}
    seen = set(status.values())

    while True:
        his = min(status, key=len)
        cur = status.pop(his)
        if all(cur): return len(his)

        cs = (tuple(not c for c in cur[:i][::-1]) + cur[i:] for i in indices)
        news = {his + (i,): c for i, c in zip(indices, cs) if c not in seen}
        seen |= set(news.values())
        status.update(news)
        
if __name__ == '__main__':
    infile = 'B-small-attempt0.in'

    from time import time

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
