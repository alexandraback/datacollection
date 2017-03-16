# Extract digits from an integer into a set.
def extract(y):
    return set([int(j) for j in str(y)])

# Number of test cases.
T = input()

for i in range(T):
    N = input()
    # List of unmatched heights so far.
    heights = []

    for j in range(2 * N - 1):
        line = [int(n) for n in raw_input().split()]
        new_heights = []

        # A soldier is counted twice: once in his row and once in his column.
        # Thus, if he was counted in a previous line, remove him from the
        # list of unmatched heights.
        for height in line:
            if height in heights:
                heights.remove(height)
            else:
                new_heights.append(height)

        heights += new_heights

    heights.sort()

    print "Case #%d: " % (i + 1),
    for height in heights:
        print height,
    print