def getPairsGenerator(x):
    orig = str(x)
    g = ((x, int(orig[n:] + orig[:n])) for n in xrange(1, len(orig)))
    return g

def getPairs(n, a, b):
    '''
    n is the base number
    ais lower bound
    b is upper bound
    '''
    gen = getPairsGenerator(n)
    def checkBounds(x):
        if x[1] < a or b < x[1]:
            return False
        if x[0] >= x[1]:
            return False
        return True
    return filter(checkBounds, gen)

def solveRange(a, b):
    solution = []
    for x in xrange(a, b+1):
        solution.extend(getPairs(x, a, b))
    return set(solution)

#main starts here
inp = open('testreal.in').read().strip().split('\n')
print inp
inp[0] #unimportant
output = ''
for i in xrange(int(inp[0])):
    rnge = inp[i+1].strip().split(' ')
    sol = solveRange(int(rnge[0]), int(rnge[1]))
    out = 'Case #' + str(i+1) + ': ' + str(len(sol)) +  '\n'
    output += out
    print out

outfile = open('out.txt', 'w')
outfile.write(output)
outfile.close()
