
def solve(grid):
    count = {}
    for row in grid:
        for n in row:
            count[n] = count.get(n, 0) + 1
    missing = []
    for n in count:
        if count[n] % 2 == 1:
            missing.append(n)
    return sorted(missing)

def run(name):
    f = open('{0}.in'.format(name), 'r')
    g = open('{0}.out'.format(name), 'w')

    T = int(f.readline())
    for t in range(T):
        N = int(f.readline())
        grid = [None] * (2*N-1)
        for i in range(2*N-1):
            grid[i] = [int(k) for k in f.readline().split()]
        missing = solve(grid)
        g.write("Case #{0}: {1}\n".format(t+1, ' '.join([str(k) for k in missing])))

    f.close()
    g.close()

if __name__ == '__main__':
    run('B-large')
