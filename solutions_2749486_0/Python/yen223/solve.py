import argparse
from collections import deque
def get_neighbours(x,y,path):
    n = len(path) + 1
    res = {
            'E':(x+n, y, path+'E'),
            'W':(x-n, y, path+'W'),
            'N':(x, y+n, path+'N'),
            'S':(x, y-n, path+'S'),
    }
    return res
def solve(x, y):
    '''
    Returns the solution 
    '''
    #Insert code here
    stack = deque()
    stack.append((0,0, ''))
    visited = set()
    while 1:
        curx, cury, path = stack.popleft()
        if (curx, cury) in visited:
            continue
        visited.add((curx, cury))
        print '({},{}),{}'.format(curx, cury, path)
        if curx == x and cury == y:
            return path
        nodes = get_neighbours(curx,cury,path)
        if x > curx:
            stack.append(nodes['E'])
            stack.append(nodes['W'])
        else:
            stack.append(nodes['W'])
            stack.append(nodes['E'])
        if y > cury:
            stack.append(nodes['N'])
            stack.append(nodes['S'])
        else:
            stack.append(nodes['N'])
            stack.append(nodes['S'])

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        #Read input files here
        T = int(inp.readline())
        for idx in range(1, T+1):
            x,y = [int(x) for x in inp.readline().split()]
            s = solve(x,y)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)

    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
