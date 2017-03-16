from copy import copy

def prob(n, x, y, grid = [], currx = 0):
    if n == 0:
        if (x, y) in grid and (x + 1, y) in grid and (x - 1, y) in grid and (x, y+1) in grid and (x, y-1) in grid:
            return 1.0
        else:
            return 0.0

    maxPt = max(filter(lambda x: x[0] == currx, grid) + [(currx, -1)], key=lambda x: x[1])

    tries = 0
    totalProb = 0

    if maxPt[1] != -1:
        if (maxPt[0]+1, maxPt[1]) not in grid:
            totalProb += prob(n, x, y, grid, currx + 1)
            tries += 1

        if (maxPt[0]-1, maxPt[1]) not in grid:
            totalProb += prob(n, x, y, grid, currx - 1)
            tries += 1

    if tries == 0:
        return prob(n-1, x, y, grid + [(maxPt[0], maxPt[1]+2), (maxPt[0]+1, maxPt[1]+1), (maxPt[0]-1, maxPt[1]+1), (maxPt[0], maxPt[1]), (maxPt[0], maxPt[1] + 1)])
    else:
        return totalProb / tries

if __name__ == '__main__':
    nb = int(raw_input())
    for i in xrange(nb):
        N, X, Y = map(int, raw_input().split())
        print "Case #" + str(i+1) + ": " + str(prob(N, X, Y))
