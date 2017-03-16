from fractions import Fraction
import math

with open("C-small-2-attempt0.in") as infile:
    with open("C.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            nlines = int(next(infile))
            hikers = []

            for L in range(nlines):
                D, H, M = map(int, next(infile).split())

                for i in range(H):
                    hikers.append((D, M+i))

            hikers.sort()
            scores = []

            for i, h in enumerate(hikers):
                d, m = h

                time = Fraction(m) * (360 - d) / 360

                score = 0

                for j in range(len(hikers)):
                    if i != j:
                        d2, m2 = hikers[j]

                        laps = time * 1 / Fraction(m2) + Fraction(d2) / 360

                        if laps <= 1:
                            score += 1
                        else:
                            score += int(laps - 1)

                scores.append(score)

            print("Case #{}: {}".format(case, min(scores)), file=outfile)

                

            
            
