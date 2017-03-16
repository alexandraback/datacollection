def count(n, points):
    count_dict = {}
    for p in points:
        for x in p:
            count_dict.setdefault(x, 0)
            count_dict[x] += 1
    missing = [x for x in count_dict if count_dict[x] % 2 == 1]
    missing.sort()
    return ' '.join(str(x) for x in missing)

def main():
    for _ in range(int(input())):
        n = int(input())
        points = [tuple(map(int, input().split())) for _ in range(2 * n - 1)]
        print('Case #' + str(_ + 1) + ': ' + count(n, points))

if __name__ == '__main__':
    main()
