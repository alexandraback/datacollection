def gen_jps(J, P, S):
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(S):
                yield (j, p, s)


def inc_key(dictionary, key):
    if key in dictionary:
        dictionary[key] += 1
    else:
        dictionary[key] = 1


def dec_key(dictionary, key):
    dictionary[key] -= 1

N = 10
    
def dfs(JPS, v, jps_visited, k, jp_visited, js_visited, ps_visited, on_found):
    ok = False
    while v < len(JPS):
        j, p, s = JPS[v]
        jps = N*(N*j + p) + s
        jp = N*j + p
        js = N*j + s
        ps = N*p + s
        if jps_visited[jps] > 0:
            v += 1
            continue
        if jp_visited[jp] >= k:
            v += 1
            continue
        if js_visited[js] >= k:
            v += 1
            continue
        if ps_visited[ps] >= k:
            v += 1
            continue
        ok = True
        jps_visited[jps] += 1
        jp_visited[jp] += 1
        js_visited[js] += 1
        ps_visited[ps] += 1
        ok = False
        dfs(JPS, v, jps_visited, k, jp_visited, js_visited, ps_visited, on_found)
        jps_visited[jps] -= 1
        jp_visited[jp] -= 1
        js_visited[js] -= 1
        ps_visited[ps] -= 1
        v += 1
    if not ok:
        on_found(jps_visited)

class StopEx(Exception):
    pass

        

def test(j, p, s, k):
    JPS = list(gen_jps(j, p, s))

    l = min(j*p*s, j*p*k, j*s*k, p*s*k)
    n = [
        0,
        [],
    ]
    def update(n, l, x):
        s = sum(x)
        if s > n[0]:
            n[0] = s
            n[1] = x[:]
            if s == l:
                raise StopEx
    try:
        dfs(JPS, 0, [0]*1000, k, [0]*1000, [0]*1000, [0]*1000,
            lambda x: update(n, l, x))
    except StopEx:
        pass

    result = []
    for i in xrange(len(n[1])):
        if n[1][i]:
            result.append((
                i / N / N,
                i / N % N,
                i % N,
            ))
    return result


import sys

number_of_cases = int(sys.stdin.readline().strip())
for case_no in xrange(number_of_cases):
    j, p, s, k = map(int, sys.stdin.readline().split())
    result = test(j, p, s, k)
    print 'Case #%d: %d' % (case_no + 1, len(result))
    for u, v, w in result:
        print u+1, v+1, w+1

#print test(1,3,3,10)
