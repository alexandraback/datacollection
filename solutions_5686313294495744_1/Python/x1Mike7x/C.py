import os
from collections import defaultdict


CUR_DIR = os.path.dirname(os.path.realpath(__file__))


def read_test(f):
    raw = []
    with open(f, 'r') as ifs:
        for case in ifs.read().split('\n')[1:]:
            if case.strip():
                raw.append(case.strip())
    tests = []
    for x in raw:
        try:
            n = int(x)
            tests.append([])
        except:
            tests[-1].append(tuple(x.split()))
    return tests



def dfs(graph, used, v, match):
    if used[v]:
        return False
    used[v] = True
    for to in graph[v]:
        if match[to] == -1 or dfs(graph, used, match[to], match):
            match[to] = v
            return True
    return False


def solve_case(case):
    lw, rw = dict(), dict()
    il, ir = 0, 0
    for l, r in case:
        if l not in lw:
            lw[l] = il
            il += 1
        if r not in rw:
            rw[r] = ir
            ir += 1
    graph = [[] for _ in range(il)]
    for l, r in case:
        x, y = lw[l], rw[r]
        graph[x].append(y)
    match = [-1] * ir
    pre_used = [False] * il
    for v in range(il):
        for to in graph[v]:
            if match[to] == -1:
                match[to] = v
                pre_used[v] = True
                break

    for v in range(il):
        if pre_used[v]:
            continue
        used = [False] * il
        dfs(graph, used, v, match)
    ul, ur = set(), set()
    n = 0
    for to in range(ir):
        v = match[to]
        ul.add(v)
        ur.add(to)
        n += 1
    for v in range(il):
        if v not in ul:
            n += 1
    for (v) in range(ir):
        if v not in ur:
            n += 1
    return len(case) - n
    


def solve(cases):
    for case in cases:
        yield solve_case(case)
           

def save(f, asnwers):
    with open(f, 'w') as ofs:
        for case, ans in enumerate(asnwers):
            ofs.write('Case #%d: %s\n' % (case + 1, str(ans))) 


def main():
    for f in os.listdir(CUR_DIR):
        if f.startswith('C') and f.endswith('e.in') or f == 'input.in':
            print(f)
            tests = read_test(f)
            answers = solve(tests)
            save(CUR_DIR + os.path.sep + f.replace('.in', '.out'), answers)
            print('Done!')


if __name__ == '__main__':
    main()
