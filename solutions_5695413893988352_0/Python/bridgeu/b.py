import sys

def read_ints(inp):
    return [int(x) for x in inp.readline().split()]

def handle(inp, i):
    c_in, j_in = inp.readline().split()

    def get_possibles(c, j):
        if len(c) == 0:
            return [["", ""]]

        poss = []

        c0 = c[0]
        j0 = j[0]

        if c0 == "?" and j0 == "?":
            poss.append(["0", "0"])
            poss.append(["0", "9"])
            poss.append(["9", "0"])
            poss.append(["0", "1"])
            poss.append(["1", "0"])
        elif c0 == "?":
            j_int = int(j0)
            poss.append([ str((j_int+9) % 10),j0])
            poss.append([ j0,j0])
            poss.append([ str((j_int+1) % 10),j0])
            poss.append(["9",j0])
            poss.append(["0",j0])
        elif j0 == "?":
            c_int = int(c0)
            poss.append([ c0, str((c_int+9) % 10)])
            poss.append([ c0, c0])
            poss.append([ c0, str((c_int+1) % 10)])
            poss.append([ c0, "0"])
            poss.append([ c0, "9"])
        else:
            poss.append([c0, j0])

        rest = get_possibles(c[1:], j[1:])

        return [[firstc + restc, firstj + restj] for [firstc, firstj] in poss for [restc, restj] in rest]

    all_poss = get_possibles(c_in, j_in)

    bestc, bestj = [None, None]
    bestDiff = 999999999999999999999999999999999999999999999999
    for [possc, possj] in all_poss:
        diff = abs(int(possc) - int(possj))
        if diff < bestDiff:
            bestc = possc
            bestj = possj
            bestDiff = diff
        elif diff == bestDiff and (int(possc) < int(bestc) or (possc == bestc and int(possj) < int(bestj))):
            bestc = possc
            bestj = possj
            bestDiff = diff

    return "%s %s" % (bestc, bestj)

f_in = sys.stdin
N = int(f_in.readline())
f_out = sys.stdout

for i in range(N):
    f_out.write("Case #%i: " % (i+1))
    result = handle(f_in, i)
    f_out.write(result)
    f_out.write("\n")
