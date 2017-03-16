#Henry Maltby
#Code Jam 2016

def rank_file(lines):
    """
    Determines which elements are missing from the table my inspecting parity.
    Because each row and each column is sorted, the missing row or column is
    precisely these missing elements, sorted.
    """
    intset = set()
    for line in lines:
        for i in line:
            if i in intset:
                intset.remove(i)
            else:
                intset.add(i)
    missing = []
    for i in intset:
        missing.append(i)
    missing.sort()
    return " ".join([str(x) for x in missing])

f = open('B-large.in')
g = open('B-large.out', 'w')

T = int(f.readline())
for i in range(T):
    N = int(f.readline())
    lines = []
    for j in range(2*N - 1):
        lines.append([int(x) for x in f.readline().split(' ')])
    g.write("Case #" + str(i + 1) + ": " + rank_file(lines) + "\n")