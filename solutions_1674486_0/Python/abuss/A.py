from string import rstrip
from sys import stdin, stdout

input = []
for line in stdin: input.append(rstrip(line,'\n'))
nTestCases = int(input.pop(0))
testcase = 1
d = 0

def findnodes(nextnode):
    global currentway, visited, cs, destnode, npaths
    if nextnode == destnode:
        npaths +=1
        if d: print currentway
        if npaths >= 2: return npaths
    visited[nextnode] = 1
    currentway.append(nextnode)
    for c in cs[nextnode]:
        if visited[c]: continue
        if findnodes(c) >= 2: return npaths
    visited[nextnode] = 0
    currentway.pop()
    return npaths

while True:
    destnode = 0
    currentway = []
    cs = []
    stdout.write("Case #%s: "%testcase)
    tokens = input.pop(0).split(' ')
    N = int(tokens.pop(0))
    cs = []
    for i in xrange(N):
        tokens = input.pop(0).split(' ')
        tokens.pop(0)
        cs.append([])
        for _ in tokens:
            cs[i].append(int(_)-1)
    destnode = -1
    if d:
        print N
        print cs
    while 1:
        visited = [0 for _ in xrange(N)]
        destnode +=1
        if destnode == N: break
        if d: print "Searching", destnode
        for i in xrange(N):
            npaths = 0
            if findnodes(i) >= 2:
                break
        if npaths>=2: break
    if npaths>=2: stdout.write("Yes\n")
    else: stdout.write("No\n")
    if testcase >= nTestCases: break
    testcase +=1
