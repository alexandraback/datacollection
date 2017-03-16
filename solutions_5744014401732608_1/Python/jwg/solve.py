#google code jam I/O template
import string
import collections

def p(x):
    return (x.bit_length()+1)

def ways(n):
    #number of ways for n-node fully-connected graph
    return 2**(n-2)

def solve(B, M):
    result = [[0]*B for i in range(B)]
    for i in range(B-1):
        result[i][i+1] = 1
    #buildings ==> M
    #1 0
    #2 1
    #3 2
    #4 4
    #5 8
    #6 16
    #k 2^(k-2)
    if M == 1:
        return result
    fullyConnected = p(M)
    numWays = ways(fullyConnected)
    assert numWays <= M

    if fullyConnected > B or (fullyConnected == B and numWays < M):
        return False

    #make last buildings fully-connected
    for i in range(B-2, B-fullyConnected-1, -1):
        result[i] = [0] * (i+1) + [1] * (B-i-1)

    remaining = M - numWays
    building = fullyConnected - 1
    while building >= 1:
        if ways(building) <= remaining:
            remaining -= ways(building)
            result[B-fullyConnected-1][B-building] = 1
        building -= 1
    
    assert remaining == 0

    return result


numCases = input()
for caseNum in range(1, numCases+1):
    #read single-line input
    B, M = map(int, raw_input().split(" "))
    ans = solve(B, M)
    if ans == False:
        print "Case #%d: IMPOSSIBLE" % (caseNum)
    else:
        print "Case #%d: POSSIBLE" % (caseNum)
        for line in ans:
            print "".join(map(str, line))
        





