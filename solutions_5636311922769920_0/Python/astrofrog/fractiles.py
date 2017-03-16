# Author: Thomas P. Robitaille
# Executed using Python 3

# In the simple case where S = K, it is sufficient to simply look at the S
# first tiles in the sequence. If the first tile in the original sequence was
# G, then at least the K first tiles in the final sequence will be G. If the
# first tile in the sequence was L, then the first K tiles in the final
# sequence will be the original tiles, so then will will know either way
# whether there is a G in the original sequence!

# For now, this just assumes that if S < K, the problem is impossible

with open('D-small-attempt0.in', 'r') as f:
    t = int(f.readline())
    for i in range(t):
        K, C, S = (int(x) for x in f.readline().split())
        if K <= S:
            print("Case #{0}: {1}".format(i + 1, ' '.join(str(j) for j in range(1, S + 1))))
        else:
            print("Case #{0}: IMPOSSIBLE".format(i + 1))
