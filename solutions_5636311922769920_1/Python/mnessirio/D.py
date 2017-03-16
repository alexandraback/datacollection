task = "D-large"
infile = open('in/%s.in' % task, 'r')
outfile = open('out/%s.out' % task, 'w')
T = int(infile.readline())


def solve():
    (K, C, S) = [int(x) for x in infile.readline().split(' ')]
    min_students_needed = (K-1)//C + 1
    if S < min_students_needed:
        return "IMPOSSIBLE"
    if K == 1:
        return '1'
    if C == 1:
        return ' '.join([str(i+1) for i in range(K)])

    tiles = []
    for j in range(min_students_needed):
        tile = C * j * K**(C-1)
        for z in range(1, C):
            tile += K**(C-z-1) * min(C*j + z, K-1)
        tiles.append(tile)

    return ' '.join([str(i+1) for i in tiles])

for case in range(1, T+1):
    outfile.write("Case #%d: %s\n" % (case, solve()))

infile.close()
outfile.close()
