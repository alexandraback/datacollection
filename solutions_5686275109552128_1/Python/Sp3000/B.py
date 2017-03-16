import math

with open("B-large.in") as infile:
    with open("B.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases+1):
            _ = int(next(infile))
            diners = list(map(int, next(infile).split()))            
            ndiners = len(diners)

            diners = [[x, 1] for x in diners]
            best = max(x[0] for x in diners)
            
            for minute in range(best):
                m = max(range(ndiners), key=lambda i:diners[i][0]/diners[i][1])
                best = min(best, minute + math.ceil(diners[m][0]/diners[m][1]))

                diners[m][1] += 1

            print("Case #{}: {}".format(case, best), file=outfile)
