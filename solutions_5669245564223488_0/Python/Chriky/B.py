import codejam as gcj
import codejam.iterators as itr
import codejam.graphs as gph

def fact(n):
    f = 1
    for i in range(1, n + 1):
        f *= i
    return f

T = gcj.read_input('i')
for t in range(T):
    N, cars = gcj.read_input('i', 's[<]')
    alphabet = sorted(set(''.join(cars)))
    counts = {l:[0, 0, 0] for l in alphabet}
    pure = [c for c in cars if len(set(c)) == 1]
    cars = [c for c in cars if c not in pure]
    for i, c in enumerate(cars):
        compressed = c[0]
        for x, y in itr.window(c, 2):
            if x != y:
                compressed += y
        cars[i] = compressed

    #print cars
    G = gph.DiGraph()
    G.add_nodes_from(alphabet)

    for c in cars:
        counts[c[0]][0] += 1
        counts[c[-1]][1] += 1
        for a in c[1:-1]:
            counts[a][2] += 1

        for a, b in itr.window(c, 2):
            if a != b:
                G.add_edge(a, b)

    acyclic = gph.is_directed_acyclic_graph(G)
    well_ordered = max(G.out_degree().values()) <= 1 and max(G.in_degree().values()) <= 1
    answer = 1
    if acyclic and well_ordered:
        chunks = gph.connected_component_subgraphs(G.to_undirected())
        for H in chunks:
            for l in H:
                if counts[l][0] > 1 or counts[l][1] > 1 or counts[l][2] != 0:
                    if sum(counts[l]) > 1:
                        answer = 0
                else:
                    pure_pieces = [p for p in pure if l in p]
                    pure_orders = fact(len(pure_pieces))
                    answer = (answer * pure_orders) % 1000000007
        chunk_orders = fact(len(chunks))
        answer = (answer * chunk_orders) % 1000000007
    else:
        answer = 0

    print 'Case #%i:' % (t + 1), answer