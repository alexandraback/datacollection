# Find the most significant digit in a binary representation, max out the
# number of paths to that in the ordered DAG, then add hops for less
# significant digits.

def getConnections(numBuildings, numPaths):
    if numPaths > 2**(numBuildings-2):
        return None

    connections = ['0'*numBuildings for i in range(numBuildings)]

    if numPaths == 0:
        return connections

    for i in range(numBuildings-1):
        connections[i] = connections[i][:i+1] + '1' + connections[i][i+2:]
    
    binaryNumPaths = bin(numPaths)[2:]
    numDigits = len(binaryNumPaths)

    for i in range(numDigits):
        connections[i] = connections[i][:i+1] + '1'*(numDigits-i) + connections[i][1+numDigits:]

    reverseBinary = binaryNumPaths[::-1]
    for i in range(len(reverseBinary)-1):
        if reverseBinary[i] == '1':
            connections[i+1] = connections[i+1][:-1] + '1'

    return connections
    

inputF = open('B-small-attempt0.in', 'r')
output = open('B-small-attempt0.out', 'w')

numCases = int(inputF.readline())

for i in range(numCases):
    line = [int(x) for x in inputF.readline().split()]
    numBuildings = line[0]
    numPaths = line[1]

    connections = getConnections(numBuildings, numPaths)

    if not connections:
        output.write('Case #' + str(i+1) + ': ')
        output.write('IMPOSSIBLE\n')
    else:
        output.write('Case #' + str(i+1) + ': ')
        output.write('POSSIBLE\n')
        for connection in connections:
            output.write(connection + '\n')

inputF.close()
output.close()

