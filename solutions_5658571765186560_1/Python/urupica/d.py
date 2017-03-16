#!/usr/bin/python

import sys, datetime
from itertools import combinations as comb

def get_component(neigh, root):
    visited = set()
    stack = [root]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(neigh[vertex] - visited)
    return visited

def get_neigh(vertices):
    neigh = {v:set() for v in vertices}
    for v,w in comb(vertices,2):
        (a,b) = v
        (c,d) = w
        if a == c and abs(b-d) == 1 or b == d and abs(a-c) == 1:
            neigh[v].add(w)
            neigh[w].add(v)
    return neigh

def rotate(vertices):
    return norm([(v[1],-v[0]) for v in vertices])

def flip(vertices):
    return [(-v[0],v[1]) for v in vertices]

def norm(vertices):
    xm = min(v[0] for v in vertices)
    ym = min(v[1] for v in vertices)
    vertices2 = []
    for v in vertices:
        vertices2.append((v[0]-xm,v[1]-ym))
    return tuple(sorted(vertices2))

def get_all_equivalent(vertices):
    transformed = set()
    for i in xrange(4):
        vertices = rotate(vertices)
        transformed.add(vertices)
    vertices = flip(vertices)
    for i in xrange(4):
        vertices = rotate(vertices)
        transformed.add(vertices)
    return transformed

mem1 = {}
def get_all_shapes(x):
    global mem1
    if x in mem1:
        return mem1[x]
    big_grid = [(i,j) for i in xrange(x) for j in xrange(x)]
    shapes = set()
    for vertices in comb(big_grid, x):
        neigh = get_neigh(vertices)
        if len(get_component(neigh,vertices[0])) == x:
            found = False
            for equiv in get_all_equivalent(vertices):
                if equiv in shapes:
                    found = True
                    break
            if not found:
                shapes.add(norm(vertices))
    mem1[x] = shapes
    return shapes

mem2 = {}
def solve(x,r,c):
    global mem2
    if x >= 7:
        return 'RICHARD'
    if r*c % x != 0:
        return 'RICHARD'
    if (x,r,c) in mem2:
        return mem2[(x,r,c)]
    if (x,c,r) in mem2:
        return mem2[(x,c,r)]
    grid = [(i,j) for i in xrange(c) for j in xrange(r)]
    for vertices in get_all_shapes(x):
        possible = False
        for z in (1,2):
            if possible:
                break
            vertices = rotate(vertices)
            xm = max(v[0] for v in vertices)
            ym = max(v[1] for v in vertices)
            for i in xrange(c-xm):
                if possible:
                    break
                for j in xrange(r-ym):
                    vertices2 = set()
                    for v in vertices:
                        vertices2.add((v[0]+i,v[1]+j))
                    rest = set(grid)-vertices2
                    filled = True
                    neigh = get_neigh(rest)
                    while rest:
                        comp = get_component(neigh,rest.pop())
                        if len(comp) % x != 0:
                            filled = False
                            break
                        rest -= comp
                    if filled:
                        possible = True
                        break
        if not possible:
            mem2[(x,r,c)] = 'RICHARD'
            return 'RICHARD'
    mem2[(x,r,c)] = 'GABRIEL'
    return 'GABRIEL'

def main():
    timeStart = datetime.datetime.now()
    (inputFile, outputFile) = openFiles()
    testCases = int(inputFile.readline().strip())
    printHeader(testCases, outputFile)

    for testCaseNumber in xrange(1, testCases+1):
        x,r,c = map(int, inputFile.readline().strip().split())
        string = 'Case #%d: %s' % (testCaseNumber, solve(x,r,c))
        print string
        if outputFile:
            outputFile.write(string + '\n')

    printFooter(outputFile, timeStart)
    closeFiles(inputFile, outputFile)


def openFiles():
    inputFile = open(sys.argv[1])
    outputFile = None
    if len(sys.argv) >= 3:
        outputFile = open(sys.argv[2], 'w')
    return (inputFile, outputFile)


def closeFiles(inputFile, outputFile):
    inputFile.close()
    if outputFile:
        outputFile.close()

def printHeader(testCases, outputFile):
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if outputFile:
        print 'Writing to %s' % sys.argv[2]
    else:
        print 'No output file'
    print '-----------------'

def printFooter(outputFile, timeStart):
    print '-----------------'
    if outputFile:
        print 'Written to %s' % sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timeStart)
    print '-----------------'

if __name__=='__main__':
    main()
