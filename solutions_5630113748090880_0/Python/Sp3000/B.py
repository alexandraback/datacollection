from collections import Counter

with open("B-small-attempt0.in") as infile:
    with open("B.out", "w") as outfile:
        T = int(next(infile))

        for case in range(1, T+1):
            N = int(next(infile))
            numbers = Counter()

            for _ in range(2*N-1):
                line = list(map(int, next(infile).split()))
                numbers.update(line)

            print("Case #{}:".format(case),
                  *sorted([k for k,v in numbers.items() if v%2 == 1]),
                  file=outfile)
                                               
