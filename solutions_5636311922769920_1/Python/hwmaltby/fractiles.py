#Henry Maltby
#Code Jam 2016

def fractile(K, C, S):
    """
    Takes three integers as input, solves the problem.
    Does so by attempting to create a particular solution, the existence of
    which is necessary for there to be any solution. Notes that the K-ary
    representation of the placement of a block gives information about the
    type of block in the original sequence with placement at each of its
    digits (0-indexing).
    """
    if S * C < K:
        return "IMPOSSIBLE"

    lst = []
    i = 0
    while i < K:
        lst.append(str(k_ary(i, K, C) + 1)) #add 1 to undo 0-indexint
        i += C
    return " ".join(lst)

def k_ary(n, k, c):
    """
    .
    """
    if c == 1 or n == k - 1:
        return n
    return n + k * k_ary(n + 1, k, c - 1)

f = open('D-large.in')
g = open('D-large.out', 'w')

N = int(f.readline())
data = [[int(x) for x in line.split(' ')] for line in f.read().split('\n')]

i = 0
for lst in data:
    g.write("Case #" + str(i + 1) + ": " + fractile(data[i][0], data[i][1], \
        data[i][2]) + "\n")
    i += 1
