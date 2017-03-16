FILENAME = "B-small-attempt1"




def solve(ll, fl, n = 3):
    unique_heights = set(fl)

    # First find out the heights of those in our missing list
    missing_heights = set()
    for height in unique_heights:
        occurance = fl.count(height)
        if occurance % 2:
            missing_heights.add(height)

    missing_heights = list(missing_heights)
    missing_heights.sort()
    return " ".join([str(x) for x in missing_heights])


with open(FILENAME + ".in") as infile:
    with open(FILENAME + ".out", 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            n = int(infile.readline())

            alllines = []

            for j in range(2 * n - 1):
                strip = infile.readline().split()
                strip = [int(x) for x in strip]
                alllines.append(strip)

            fulllines = []
            for ll in alllines:
                fulllines += ll

            outfile.write("Case #%d: %s\n" % (i + 1, solve(alllines, fulllines, n)))
