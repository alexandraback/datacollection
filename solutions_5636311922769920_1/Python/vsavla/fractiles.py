import re


def main():
    t = int(input())

    for i in range(1, t+1):
        kcs = input().split()
        k, c, s = int(kcs[0]), int(kcs[1]), int(kcs[2])
        print("Case #%d: " % i, end='')
        if s == k:
            for res in range(1, s):
                print(res, end=' ')
            print(s)
        else:
            all_tiles = []
            for j in range(0, k):
                temp = 'l' * (k - 1)
                original = temp[:j] + 'g' + temp[j:]
                tiles = original
                for z in range(1, c):
                    tiles = re.sub('g', 'g' * k, tiles)
                    tiles = re.sub('l', original, tiles)
                    tiles = tiles[:k]
                all_tiles.append(tiles)
            row_start = 0
            path = []
            for clean in range(0, s):
                num_g, greatest = greatest_col(all_tiles, row_start, k)
                path.append(num_g+1)
                row_start += greatest
                if row_start >= k:
                    break
            if row_start < k:
                print("IMPOSSIBLE")
            else:
                print(*path)


def greatest_col(all_tiles, row_start, k):
    greatest = 0
    index = 0
    for i in range(0, k):
        temp = 0
        for j in range(row_start, k):
            if all_tiles[j][i] == 'l':
                break
            temp += 1
        if temp > greatest:
            greatest = temp
            index = i
    return index, greatest
if __name__ == '__main__':
    main()