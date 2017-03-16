# USE DAG approach

def get_max(b):
    return sum(range(1, b - 1)) + 1

def solve(b, m):
    # Check for DAG solvability
    matrix = [[0 for i in xrange(b)] for j in xrange(b)]
    if m > get_max(b):
        return ["IMPOSSIBLE"]

    # Start with all linearly connected
    for i in xrange(b - 1):
        matrix[i][i + 1] = 1

    m = m - 1 # initial linear connection

    c = 0
    while m > 0:
        for i in xrange(b - 2  - c):
            if m == 0:
                break
            #print "C ({0}, {1})".format(c, 2 + i)
            matrix[c][2 + i + c] = 1
            m = m - 1

        c = c + 1


    # Convert to 1D string array
    matrix = [''.join(str(mm) for mm in m) for m in matrix]
    matrix.insert(0, "POSSIBLE")
    return matrix



test_cases = int(raw_input())
for i in xrange(1, test_cases + 1):
    b, m = [int(s) for s in raw_input().split(" ")]

    print "Case #{0}: {1}".format(i, '\n'.join(solve(b, m)))
