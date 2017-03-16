import sys

""" Digest Code Jam. Usages: 
$ python script < input > output
PS > gc input | python script | sc output."""

def readints():
    return list(map(int, sys.stdin.readline().strip().split(' ')))


def reachable(graph, node):
    to_crawl = [node]
    crawled = []
    while to_crawl:
        current = to_crawl.pop()
        for neighbor in graph[current]:
            if (neighbor != current) and (neighbor not in crawled) and (neighbor not in to_crawl):
                to_crawl.append(neighbor)
        if current != node: crawled.append(current) 
    return crawled

def has_d(graph):
    r_graph = {}
    for node in graph:
        r_graph[node] = reachable(graph, node)
    for node in r_graph:
        p_nodes = r_graph[node]
        for p in p_nodes:
            for bridge1 in p_nodes + [node]:
                for bridge2 in p_nodes + [node]:
                    if (bridge1 != bridge2 and 
                        p in r_graph[bridge1] and p in r_graph[bridge2] and 
                        p in graph[bridge1] and p in graph[bridge2]): 
#                        print node, p, bridge1, bridge2
                        return True
    return False

if __name__ == '__main__':
    numcases = readints()[0]
    for i in range(numcases):
        casenum = i + 1
        numcls = readints()[0]
        data = [readints() for _ in range(numcls)]
        graph = {}
        for j, d in enumerate(data):
            graph[j+1] = d[1:]
        answer = 'Yes' if has_d(graph) else 'No'
        print 'Case #%d: %s' % (casenum, answer)
