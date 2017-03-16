fin = open('B-small-attempt0.in', 'r')
fout = open('output.txt', 'w')

t = int(fin.readline())

def maxWays(b):
    return 2**(b - 2)

for i in xrange(t):
    print i
    b, m = map(int, fin.readline().split())

    if maxWays(b) < m:
        fout.write('Case #' + str(i + 1) + ': IMPOSSIBLE\n')
    else:
        fout.write('Case #' + str(i + 1) + ': POSSIBLE\n')
        connections = []
        for j in xrange(b):
            connections += [[0]*b]
        ways = 1
        node = b - 1
        connections[0][node] = 1
        while m > ways:
            if m >= 2*ways:
                ways *= 2
                node -= 1
                connections[0][node] = 1
                for j in xrange(b - 1 - node):
                    connections[node][b - j - 1] = 1
            else:
                node -= 1
                connections[0][node] = 1
                node2 = node
                while ways < m:
                    node2 += 1
                    waysA = 2**(b - node2 - 1)
                    if ways + waysA <= m:
                        connections[node][node2] = 1
                        ways += waysA
        for j in xrange(b):
            fout.write(''.join(str(x) for x in connections[j]) + '\n')
            

fout.close()

print 'FINISHED'
