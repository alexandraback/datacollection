import sys
import string

"""
Key Insight:
Suppose we have a tree of fractile sequences. The root has edges to all of the nodes on the first level. The first level has the artwork of length K and complexity 1. At the next depth, we have the artwork of complexity 2, and at the next depth, complexity 3, and so on. Each tile has an edge to all of its child tiles. We want to be able to determine if the artwork at the first level has any G tiles based off of the tiles at the leaves of the tree.

The key conclusion is that a leaf tile (a tile at the base of the tree from the sequence of complexity C) is only L if and only if all the nodes from the root to it are L. Otherwise, the tile must be G. Thus, we can uncover if the original artwork had a G tile if K <= S*C by simply choosing paths where at each node, we take a branch with respect to each node which we haven't taken before (each tile has K branches).
"""

def main():
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        K, C, S = tuple(map(int, inF.readline().split(' ')))
        # print(K,C,S)
        k = fractile(K, C, S)
        if k == None:
            k = "IMPOSSIBLE"
            ouF.write("Case #{0}: {1}\n".format(i+1, k))
        else:
            ouF.write("Case #{0}:".format(i+1))
            for n in k:
                ouF.write(" {0}".format(n))
            ouF.write("\n")
    inF.close()
    ouF.close()

def fractile(K, C, S):
    # K is the branching factor, C is the depth of our tree, S is the number of leaves we can see
    if K > C*S:
        return None
    # The leaf nodes we need to check can be determined by the path we choose which can be constructed from a K-nary string.
    seen = 0
    paths = []
    digit = 0 # branch number from 0 to K-1
    while seen < K:
        path = 0 # leaf number from 1 to K**C
        power = C - 1 # power of K, C-1 to 0
        while power >= 0:
            path += (K**power)*digit
            if digit < K - 1: # If we have not exhausted all branches, change branches
                digit += 1
            power -= 1
            seen += 1
        paths.append(path+1)
    return paths

if __name__ == '__main__':
  main()
