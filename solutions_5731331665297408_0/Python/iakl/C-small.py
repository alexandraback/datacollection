# IO file paths
file_in = "C-small-attempt0.in"
file_out = "C-small-attempt0.out"

import math

# Solves the problem
def Solve(N, M, z, f):
    visited = []
    reachable = []
    sz = sorted(z)
    zorder = []
    for szip in sz:
        for i in range(0, N):
            zip = z[i]
            if szip == zip:
                zorder.append(i)
    fmap = dict()
    for fl in f:
        if fl[0] not in fmap:
            fmap[fl[0]] = []
        if fl[1] not in fmap:
            fmap[fl[1]] = []
        if fl[0] not in fmap[fl[1]]:
            fmap[fl[1]].append(fl[0])
        if fl[1] not in fmap[fl[0]]:
            fmap[fl[0]].append(fl[1])

    for ind in range(0, len(zorder)):
        zo = zorder[ind]
        res = ''
        visited.append(zo)
        way = []
        way.append(zo)
        res = res + str(z[zorder[0]])
        nres = BuildWay(N, M, z, zorder, fmap, visited, way, res)
        if None != nres:
            return nres

def BuildWay(N, M, z, zorder, fmap, visited, way, res):
    if len(visited) == N:
        return res
    for zo in zorder:
        if zo not in visited:
            n = len(way)
            for bi in range(0, n):
                index = n - bi - 1
                curr = way[index]
                if zo in fmap[curr]:
                    lway = []
                    for j in range(0, index + 1):
                        lway.append(way[j])
                    lway.append(zo)
                    lvisited = []
                    lvisited.extend(visited)
                    lvisited.append(zo)
                    newres = res + str(z[zo])
                    lres = BuildWay(N, M, z, zorder, fmap, lvisited, lway, newres)
                    if None != lres:
                        return lres
    return None


# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        NM = lines[i].rstrip().split(' ')
        i = i + 1
        zips = []
        N, M = int(NM[0]), int(NM[1])
        for _ in xrange(0, N):
            zips.append(int(lines[i].rstrip()))
            i = i + 1
        flights = []
        for _ in xrange(0, M):
            kj = lines[i].rstrip().split(' ')
            i = i + 1
            k, j = int(kj[0]), int(kj[1])
            flights.append([k - 1, j - 1])
            
        result = str(Solve(N, M, zips, flights))
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
