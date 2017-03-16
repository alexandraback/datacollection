from sys import stdin

data = stdin.readlines()

for case, line in enumerate(data[1:], 1):
    k, c, s = map(int, line.split())
    if (s < (k+c-1)//c):
        ans = 'IMPOSSIBLE'
    else:
        indexes = []
        covered = 0
        for cleaned in range((k+c-1)//c):
            covered += 1
            index = covered
            for floor in range(c-1):
                covered = min(k, covered+1)
                index = (index-1)*k+covered
            indexes.append(index)
        ans = ' '.join(map(str, indexes))
    print('Case #{}: {}'.format(case, ans))
