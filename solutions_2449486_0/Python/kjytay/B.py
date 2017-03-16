from copy import deepcopy

# basic idea: for a given cell, if it is smaller than the maximum in its
# row, then it must be the maximum in its column, and vice versa.

def parse(lawn, N, M):
    #if N == 1 or M == 1:
    #    return "YES"
    lawnrows = deepcopy(lawn)
    lawncols = []
    for j in range(M):
        temp = []
        for i in range(N):
            temp.append(lawn[i][j])
        lawncols.append(temp)

    maxinrow = [max(line) for line in lawnrows] # row maximums
    maxincol = [max(line) for line in lawncols] # col maximums

    for i in range(N):
        for j in range(M):
            if lawn[i][j] < maxinrow[i]:
                if lawn[i][j] != maxincol[j]:
                    return "NO"
            if lawn[i][j] < maxincol[j]:
                if lawn[i][j] != maxinrow[i]:
                    return "NO"
    
    return "YES"

f = open("B-small-attempt0.in", "r")
g = open("B-small-ans0.txt", "w")

T = int(f.readline()) # no of test cases
k = 0
while k < T:
    # parse case
    [N, M] = f.readline().strip().split(" ")
    N, M = int(N), int(M)  # dimensions of lawn
    lawn = []
    for i in range(N):
           temp = f.readline().strip().split(" ")
           temp = [int(x) for x in temp]
           lawn.append(temp)

    state = parse(lawn, N, M)  # the final YES or NO
    
    # print "Case #" + str(k+1) + ": " + state
    g.write("Case #" + str(k+1) + ": " + state + "\n")

    # move on to the next case
    k += 1

f.close()
g.close()

