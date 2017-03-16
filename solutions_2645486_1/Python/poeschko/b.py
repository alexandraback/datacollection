import sys
from itertools import product

def solve_large(E, R, N, v):
    gain = 0
    potential = [E] * N
    must_keep = [0] * N
    spent = [0] * N
    v_sorted = sorted(enumerate(v), key=(lambda (index, value): (-value, index)))
    for index, value in v_sorted:
        spend = potential[index] - (must_keep[index] or 0)
        #spend = max(spend, 0)
        #print (index, spend, potential[index], must_keep[index])
        assert spend >= 0
        spent[index] = spend
        potential[index] = (must_keep[index] or 0)
        gain += spend * value
        must_have = 0
        for prev in reversed(range(N)):
            must_have -= R
            must_have = max(must_have, 0)
            must_keep[prev] = must_have
            must_have += spent[prev]
            #must_have = spend - (index - prev) * R
            #must_keep[prev] = max(must_keep[prev], must_have)
            #must_have = spend - (index - prev) * R
            """if must_have >= 0:
                if must_keep[prev] is None:
                    must_keep[prev] = must_have
                else:
                    must_keep[prev] += spend"""
            #if must_keep[prev] is None:
            #    if must_have >= 0:
            #        must_keep[prev] = must_have
            #else:
            #    must_keep[prev] += spend

        for next in range(index + 1, N):
            potential[next] = min(potential[next], min(potential[next - 1] + R, E))  #min(potential[next] - spend + (next - index) * R, E)
        #print potential
        #print must_keep
    return gain

def solve(E, R, N, v):
    max_gain = 0
    solution = None
    for spend in product(range(0, E + 1), repeat=N):
        is_valid = True
        level = E
        for i in range(N):
            level -= spend[i]
            if level < 0:
                is_valid = False
                break
            level += R
            if level > E:
                level = E
        if is_valid:
            gain = 0
            for i in range(N):
                gain += spend[i] * v[i]
            if gain > max_gain:
                max_gain = gain
                solution = spend
    #print solution
    return max_gain

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        data = []
        E, R, N = map(int, sys.stdin.readline().split())
        v = map(int, sys.stdin.readline().split())
        #print (E, R, N, v)
        result = solve_large(E, R, N, v)
        print "Case #%d: %s" % (t + 1, result)

if __name__ == '__main__':
    main()
