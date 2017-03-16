import sys
import itertools

def can_fly(a, b, flights):
    a += 1
    b += 1
    return (min(a, b), max(a, b)) in flights

def can_visit(stack, remaining, flights):
    if not remaining:
        return True
    next = remaining[0]
    new_rem = remaining[1:]
    for k in range(len(stack)):
        start = stack[k]
        if can_fly(start, next, flights):
            if can_visit(stack[:k+1] + [next], new_rem, flights):
                return True
    return False

def solve(zips, flights):
    flights = set(flights)
    best = None
    for perm in itertools.permutations(range(len(zips))):
        signature = ''.join(zips[i] for i in perm)
        stack = [perm[0]]
        feasible = can_visit(stack, perm[1:], flights)
        if feasible:
            if best is None or signature < best:
                best = signature
    return best

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        N, M = map(int, sys.stdin.readline().split())
        zips = [sys.stdin.readline().strip() for n in range(N)]
        flights = [tuple(map(int, sys.stdin.readline().split())) for m in range(M)]
        result = solve(zips, flights)
        print "Case #%d: %s" % (t + 1, result)

if __name__ == '__main__':
    main()
