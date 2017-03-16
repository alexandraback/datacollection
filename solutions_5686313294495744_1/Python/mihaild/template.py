from collections import deque, defaultdict

def readint():
    return int(input())


def readfloat():
    return float(input())


def readarray(N, foo=input):
    return [foo() for i in range(N)]


def readlinearray(foo=int):
    return list(map(foo, input().split()))


def GCD(a, b):
    while b:
        a, b = b, a % b
    return a


def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(max+1) if primes[x]]


def is_prime(N):
    i = 3
    if not(N % 2):
        return 0
    while i*i < N:
        if not(N % i):
            return 0
        i += 3
    return 1


def ford_fulkerson(edges):
    lv = set()
    rv = set()
    real_edges = defaultdict(set)
    for e in edges:
        lv.add((0, e[0]))
        rv.add((1, e[1]))
        real_edges[(0, e[0])].add((1, e[1]))
    matched_v = set()
    while True:
        d = deque()
        for v in lv:
            if v not in matched_v:
                d.append(v)
        parents = {v: None for v in d}
        new_path = None
        used = set(d)
        while d:
            v = d.popleft()
            if v[0] == 1 and v not in matched_v:
                new_path = [v]
                while parents[new_path[-1]] is not None:
                    new_path.append(parents[new_path[-1]])
                break
            for v1 in real_edges[v]:
                if v1 not in used:
                    parents[v1] = v
                    d.append(v1)
                    used.add(v1)
        else:
            break
        new_path = new_path[::-1]
        for i in range(1, len(new_path)):
            real_edges[new_path[i]].add(new_path[i - 1])
            real_edges[new_path[i - 1]].remove(new_path[i])
        matched_v.add(new_path[0])
        matched_v.add(new_path[-1])
    return matched_v


case_number = readint()
for case in range(case_number):
    N = readint()
    a = readarray(N, lambda: input().split())
    best_cov = ford_fulkerson(a)
    orig1 = len(best_cov) // 2
    lv = len(set(x[0] for x in a))
    rv = len(set(x[1] for x in a))
    orig2 = lv + rv - len(best_cov)
    print("Case #%s: %d" % (case + 1, N - orig1 - orig2))
