import sys
import logging

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger(__name__)


def clean(edges, b):
    edges2 = set(edges)
    starts = set(i for i, j in edges)
    for i, j in edges:
        if j != (b-1) and j not in starts:
            edges2.remove((i,j))
    if len(edges2) != len(edges):
        return clean(edges2, b)
    return edges


def solve(case):
    log.info('Solving: %r', case)
    b, m = case

    nodes = {0: 1}

    edges = set()

    for i in range(b):
        for j in range(i+1, b):
            if nodes.get(j, 0) + nodes[i] <= m:
                edges.add((i, j))
                nodes[j] = nodes.get(j, 0) + nodes[i]

    if nodes[b-1] != m:
        return 'IMPOSSIBLE'

    # Drop unecessary edges
    edges = clean(edges, b)

    r = 'POSSIBLE\n'

    for x, i in enumerate(range(b)):
        for y, j in enumerate(range(b)):
            if x == y or x == b-1:
                assert (i,j) not in edges
            r += ['0', '1'][(i,j) in edges]
        r += '\n'

    return r.strip()



def get_cases(lines):
    lines = [map(int, ln.split()) for ln in lines]

    for ln in lines[1:]:
        yield ln


def main():
    lines = [ln.strip() for ln in sys.stdin]

    for i, case in enumerate(get_cases(lines), 1):
        result = solve(case)
        log.info('Case #%d: %s', i, result)
        print 'Case #%d: %s' % (i, result)


if __name__ == '__main__':
    main()

