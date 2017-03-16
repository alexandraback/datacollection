import sys

def dfs(graph, root, explored_nodes=None, discovery=None, back=None):
    if explored_nodes is None:
        explored_nodes = {}
    if discovery is None:
        discovery = {}
    if back is None:
        back = {}
    explored_nodes[root] = True
    for o in graph[root]:
        e = tuple(sorted([root, o]))
        if e not in discovery and e not in back:
            if o not in explored_nodes:
                discovery[e] = True
                [explored_nodes, discovery, back] = dfs(graph, o, explored_nodes, discovery, back)
            else:
                back[e] = True
    return [explored_nodes, discovery, back]

def solver(n, graph):
    unexplored_nodes = range(1, n+1)
    while unexplored_nodes:
        root = unexplored_nodes.pop()
        [explored, disc, back] = dfs(graph, root)
        if back:
            return "Yes"
        for e in explored:
            try:
                unexplored_nodes.remove(e)
            except ValueError:
                pass
    return "No"

def ssi(s):
    """
    space separated integers
    """
    return map(int, s.strip('\n').split())

def rl():
    return sys.stdin.readline()

def debug(msg='', off=False):
    if not off:
        sys.stderr.write(str(msg) + '\n')

def main():
    # open input file
    # input_file = open('infile.txt')
    
    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        n = int(rl())
        graph = {}
        for i in xrange(1, n+1):
            other_nodes = ssi(rl())
            other_nodes.pop(0)
            graph[i] = other_nodes
        answer = solver(n, graph)
        output.append('Case #%d: %s\n' % (c+1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()



if __name__=='__main__':
    main()
