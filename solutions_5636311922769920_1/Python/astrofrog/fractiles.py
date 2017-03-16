# Author: Thomas P. Robitaille
# Executed using Python 3

# In the simple case where S = K, it is sufficient to simply look at the S
# first tiles in the sequence. If the first tile in the original sequence was
# G, then at least the K first tiles in the final sequence will be G. If the
# first tile in the sequence was L, then the first K tiles in the final
# sequence will be the original tiles, so then will will know either way
# whether there is a G in the original sequence!

# If S < K, and the complexity is 1, then there is no way that we can know the
# answer, and same goes if the complexity is >1 and S < K / 2

# If C > 1 and K / 2 <= S < K then we can focus on the K ** 2 first tiles
# starting from the first set of K tiles, and we can stride over them starting
# at the last sub-tile so that we cover all original positions either by
# checking a set of K tiles or by checking that position within K-length 
# tiles. Hard to explain without diagrams :) I think this may possibly not be 
# quite right because for larger complexities we might be able to get away 
# with fewer checks, so some things currently marked as IMPOSSIBLE may in 
# fact be possible.

with open('D-large.in', 'r') as f:
    t = int(f.readline())
    for i in range(t):
        K, C, S = (int(x) for x in f.readline().split())
        if K <= S:
            tiles = range(1, S + 1)
        else:
            if C == 1 or S < K / 2:
                print("Case #{0}: IMPOSSIBLE".format(i + 1))
                continue
            else:
                tiles = []
                for j in range(1, S + 1):
                    tiles.append(j * K - j + 1)

        print("Case #{0}: {1}".format(i + 1, ' '.join(str(j) for j in tiles)))
