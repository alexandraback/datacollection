import sys
import networkx

ZEROS = "00000000000000000000"
ONES = "11111111111111111111"

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    n = int(l)
    G = networkx.Graph()
    for j in range(0, n):
        l = sys.stdin.readline().strip()
        tokens = l.split(" ")
        G.add_edge(ZEROS + tokens[0], ONES + tokens[1])
    count = 0
    while True:
        has_removed = False
        for edge in G.edges():
            if G.degree(edge[0]) > 1 and G.degree(edge[1]) > 1:
                count += 1
                G.remove_edge(edge[0], edge[1])
                has_removed = True
        if not has_removed:
            break
    print("Case #%d: %s" % (i + 1, count))

