import sys
import pprint

sys.setrecursionlimit(10000)

def load_tests(filename):
    lines = file(filename).readlines()
    numtests = int(lines[0])
    lines.pop(0)
    tests = []
    while len(lines) > 0:
        numclasses = int(lines.pop(0))
        test = []
        for i in xrange(numclasses):
            line = lines.pop(0)
            pl = [int(x) for x in line.split()]
            assert int(pl[0]) == len(pl) - 1
            test.append(pl[1:])
            
        tests.append(test)
        
    return tests


def make_graph(inheritances):
    ret = []
    for x in inheritances:
        newl = [False, x]
        ret.append(newl)
        
    return ret
    
def find_diamond(s, graph):
    is_visited, inh = graph[s-1]
    if is_visited:
        return True
    
    graph[s-1][0] = True
    for n in inh:
        if find_diamond(n, graph):
            return True

    return False
    
def solve(inhertiances):
    for i in xrange(1, len(inhertiances) + 1):
        graph = make_graph(inhertiances)
        if find_diamond(i, graph):
            print 'Yes'
            return
    
    print 'No'
    
def main():
    tests = load_tests(sys.argv[1])
    
    for i in xrange(1, 1 + len(tests)):
        print "Case #%d:" % i, 
        solve(tests[i - 1])

if "__main__" == __name__:
    main()
    