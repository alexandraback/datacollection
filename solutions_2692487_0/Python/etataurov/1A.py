with open('A-small-attempt3.in') as input_data:
    n = int(input_data.readline())
    cases = []
    for i in range(n):
        x = [list(map(int, input_data.readline().split()))]
        y = list(map(int, input_data.readline().split()))
        x.append(y)
        cases.append(x)
print(cases)

with open('A-small-attempt3.out', 'w') as output_data:
    for i, case in enumerate(cases):
        A, N = case[0]
        Ns = case[1]
        operations1 = 0
        operations2 = 0
        others = sorted(Ns)
        print("%s %s %s" % (i+1, A, others))
        cur = A
        for ii, oth in enumerate(others):
            if oth < cur:
                cur += oth
            else:
                if ii == len(others) - 1:
                    operations1 += 1
                    continue
                diff = cur-1
                if cur + diff > oth:
                    cur += diff
                    cur += oth
                    operations1 += 1
                else:
                    operations1 += 1
        cur = A
        for ii, oth in enumerate(others):
            if oth < cur:
                cur += oth
            else:
                if ii == len(others) - 1:
                    operations2 += 1
                    continue
                diff = cur-1
                if cur + diff > oth:
                    cur += diff
                    cur += oth
                    operations2 += 1
                else:
                    while True:
                        dff = cur - 1
                        cur += dff
                        operations2 += 1
                        if operations2 > operations1:
                            break
                        if cur > oth:
                            cur += oth
                            break

        operations = min(operations1, operations2)
        output_data.write("Case #%d: %d\n" % (i+1, operations))






