T = int(input())

for t in range(1, T+1):
    N = int(input())
    lines = set()
    for n in range(2*N - 1):
        lines.add(tuple(map(int, input().split())) + (n,))

    mins = []
    for n in range(N):
        mins.append([])
        mn = None
        for line in lines:
            if mn is None:
                mn = line[n]
            if line[n] == mn:
                mins[n].append(line)
            elif line[n] < mn:
                mins[n] = [line]
                mn = line[n]

        for l in mins[n]:
            lines.remove(l)

    for n in range(N):
        if len(mins[n]) != 2:
            missing = []
            have = mins[n][0]
            for m in range(N):
                if m == n:
                    missing.append(have[n])
                    continue
                one, two = mins[m]
                if have[m] == one[n]:
                    missing.append(two[n])
                else:
                    missing.append(one[n])

            missing_str = ' '.join(map(str, missing))
            print('Case #{}: {}'.format(t, missing_str))
            break

