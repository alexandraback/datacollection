import sys
import networkx

def longest_to_i(n,a,i, took):
    res = 0
    fin_tmp_took = set()
    for k in xrange(n):
        tmp_took = set()
        m = 0
        while k not in took and k not in tmp_took and k != i:
            m += 1
            tmp_took.add(k)
            k = a[k]
        if k == i:
            if m > res:
                res = m
                fin_tmp_took = tmp_took
    for k in fin_tmp_took:
        took.add(k)
    return res

def solve1(n,a):
    took = set()
    pairs = []
    for i in xrange(n):
        if i < a[i] and a[a[i]] == i:
            pairs.append(i)
    res = 0
    for i in pairs:
        took.add(i)
        took.add(a[i])
        res += 2 + longest_to_i(n,a,i, took) + longest_to_i(n,a,a[i], took)
    return res

def solve_naive(n,a):
    res = 0
    for i in xrange(n):
        m = 1
        curr = i
        prev = None
        took = set()
        took.add(i)
        while a[curr] not in took:
            took.add(a[curr])
            m += 1
            prev = curr
            curr = a[curr]
        if a[curr] != prev and a[curr] != i:
            continue
        if a[curr] == prev:
            for k in xrange(n):
                if k not in took:
                    if a[k] == curr or a[k] == i:
                        m += 1
                        break
        if m >= res:
            print i, m
            res = m
    return res


def solve_pairs(n,a):
    dg = networkx.DiGraph()
    for i in xrange(1,n+1):
        dg.add_node(i)
    for i in xrange(n):
        dg.add_edge(i+1,a[i])
    l = list(networkx.components.strongly_connected_components(dg))
    # num_of_pairs = sum(1 for c in l if len(c)==2)
    pairs = [c for c in l if len(c) == 2]
    res = 0
    for p in pairs:
        if a.count(p[0]) > 1 or a.count([1]) > 1:
            res += 3
        else:
            res += 2
    print res
    return res

def solve_cycles(n,a):
    dg = networkx.DiGraph()
    for i in xrange(n):
        dg.add_node(i)
    for i in xrange(n):
        dg.add_edge(i,a[i])
    l = list(networkx.components.strongly_connected_components(dg))
    res = 0
    for cyc in l:
        for i in xrange(len(cyc) - 1):
            took = set()
            for k in cyc:
                took.add(k)
            m = len(cyc)# + longest_to_i(n,a,cyc[i],took) + longest_to_i(n,a,cyc[i + 1],took)
            if m > res:
                res = m
    return res

def solve(n,a):
    return max(solve1(n,a), solve_cycles(n,a))

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

results = []
T = int(input_file.readline().strip())
for i in xrange(T):
    n = int(input_file.readline().strip())
    a = [int(k)-1 for k in input_file.readline().strip().split(' ')]
    results.append(solve(n,a))

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()
