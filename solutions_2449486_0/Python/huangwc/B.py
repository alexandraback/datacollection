from sys import stdin, stdout

#   Note: the key point is every cell must have
# the maximum value of the entire row OR column.

stdin = open('B-small-attempt0.in', 'r')
stdout = open('B-small.out', 'w')

T = int(stdin.readline().strip())


for t in range(1, T+1):
    (N, M) = [int(x) for x in stdin.readline().strip().split()]
    mat = [ \
        [int(x) for x in stdin.readline().strip().split()] \
        for row in range(0, N)]

    ans = True

    for i in range(0, N):
        for j in range(0, M):
            ans = ans and \
                mat[i][j] >= min( \
                    max([x for x in mat[i]]), \
                    max([row[j] for row in mat]) \
                )

    stdout.write('Case #%d: %s\n' % (t, 'YES' if ans else 'NO'))

stdin.close()
stdout.close()
