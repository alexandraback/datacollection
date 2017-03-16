def solve(n):
    if n == 0:
        return 'INSOMNIA'

    vis = [False]*10
    val = 0
    while sum(vis) < 10:
        val += n
        for c in str(val):
            vis[int(c)] = True

    return val


def main():
    file_name = '/home/maksym/Downloads/A-large.in'
    with open(file_name, 'r') as f:
        n = int(f.readline().strip())
        values = [int(f.readline().strip()) for _ in range(n)]

    for i, v in enumerate(values):
        print('Case #{}: {}'.format(i + 1, solve(v)))


if __name__ == '__main__':
    main()
