def main():
    T = int(input())
    for case_num in range(1, T + 1):
        c, j = input().split()

        n = len(c)
        # 0 means do nothing
        # 1 means max C and min J
        # 2 means max J and min C
        state = 0
        cans = []
        jans = []
        for i in range(n):
            if c[i] != '?':
                cans.append(c[i])
            if j[i] != '?':
                jans.append(j[i])

            if state == 0:
                if c[i] == '?' and j[i] == '?':
                    cans.append(0)
                    jans.append(0)
                elif c[i] == '?' and j[i] != '?':
                    cans.append(j[i])
                elif c[i] != '?' and j[i] == '?':
                    jans.append(c[i])
                else:
                    if c[i] < j[i]:
                        state = 1
                    elif c[i] > j[i]:
                        state = 2
            elif state == 1:
                if c[i] == '?':
                    cans.append(9)
                if j[i] == '?':
                    jans.append(0)
            elif state == 2:
                if c[i] == '?':
                    cans.append(0)
                if j[i] == '?':
                    jans.append(9)

        cstr = ''.join(map(str, cans))
        jstr = ''.join(map(str, jans))
        print("Case #{0}: {1} {2}".format(case_num, cstr, jstr))

main()
