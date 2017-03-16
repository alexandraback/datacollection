def cut(row, h):
    ret = []
    for x in row:
        ret.append(x if x < h else h)
    return ret


def transpose(m):
    ret = []
    for i in range(len(m[0])):
        ret.append([row[i] for row in m])
    return ret


def main():
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')

    size = int(fin.readline())
    for i in range(1, size + 1):
        n, m = map(int, fin.readline().split())
        pattern = []
        for row in range(n):
            pattern.append(list(map(int, fin.readline().split())))
        lawn = [[100 for j in range(m)] for i in range(n)]

        for row in range(n):
            lawn[row] = cut(lawn[row], max(pattern[row]))

        lawn = transpose(lawn)
        pattern = transpose(pattern)

        for row in range(m):
            lawn[row] = cut(lawn[row], max(pattern[row]))

        ans = 'YES' if lawn == pattern else 'NO'
        print('Case #{}: {}'.format(i, ans), file=fout)

    fin.close()
    fout.close()

main()
