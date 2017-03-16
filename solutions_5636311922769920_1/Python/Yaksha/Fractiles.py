FILENAME = "D-large"

# Tile positions are index from 1!

def calculatePosition(k, c, *args):
    posAccu = 0

    for arg in args:
        posAccu += k ** (c - 1) * (arg - 1)
        c -= 1

    return posAccu + 1


def solve(k, c, s):
    if c * s < k:
       return "IMPOSSIBLE"

    positions = []
    allTiles = list(range(1, k + 1))
    while allTiles:
        (now, next) = allTiles[:c], allTiles[c:]
        positions.append(calculatePosition(k, c, *now))

        allTiles = next

    return " ".join(str(x) for x in positions)


with open(FILENAME + ".in") as infile:
    with open(FILENAME + ".out", 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            input = infile.readline().strip()
            [k, c, s] = input.split()

            outfile.write("Case #%d: %s\n" % (i + 1, solve(int(k), int(c), int(s))))
