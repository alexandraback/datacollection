with open('C-small-attempt0 (1).in') as file_in, open('C.out', 'w') as file_out:
    lines = file_in.readlines()
    cases = int(lines[0])

    for case in range(1, cases + 1):
        JP = {}
        JS = {}
        PS = {}

        j, p, s, k = map(int, lines[case].split())

        upper_limit = j * p * s
        result = []
        done = False
        for jj in range(1, j + 1):
            for pp in range(1, p + 1):
                for ss in range(1, s + 1):
                    jp = JP.get((jj, pp), 0)
                    js = JS.get((jj, ss), 0)
                    ps = PS.get((pp, ss), 0)

                    if jp < k and js < k and ps < k:
                        result.append((jj, pp, ss))
                        JP[(jj, pp)] = jp + 1
                        JS[(jj, ss)] = js + 1
                        PS[(pp, ss)] = ps + 1
        file_out.write('Case #{}: {}\n'.format(case, len(result)))
        for r in result:
            file_out.write('{}\n'.format(' '.join(str(rr) for rr in r)))


