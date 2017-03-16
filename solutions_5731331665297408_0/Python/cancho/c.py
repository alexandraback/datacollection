from itertools import izip, permutations


def zipcon(codes, perm):
    return ''.join(codes[p - 1] for p in perm)

def is_successful_trip(perm, edges):
    stack = [perm[0]]
    for from_, to_ in izip(perm[:-1], perm[1:]):
        while stack and (stack[-1], to_) not in edges:
            stack.pop()
        if not stack:
            return False
        stack.append(to_)
    return True

def answer(indices, edges, codes):
    for perm in permutations(indices):
        if is_successful_trip(perm, edges):
            return zipcon(codes, perm)

T = int(raw_input())

for t in xrange(1, T + 1):
    N, M = map(int, raw_input().strip().split())
    codes = []
    edges = set()
    tmp = []
    for i in xrange(1, N + 1):
        code = raw_input()
        codes.append(code)
        tmp.append((code, i))
    for _ in xrange(M):
        from_, to_ = map(int, raw_input().strip().split())
        edges.add((from_, to_))
        edges.add((to_, from_))

    indices = [index for code, index in sorted(tmp)]

    print 'Case #%d: %s' % (t, answer(indices, edges, codes))

