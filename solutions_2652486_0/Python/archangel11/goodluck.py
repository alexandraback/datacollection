from math import sqrt

def solve(f):
    rnmk = f.readline().split()
    r = long(rnmk[0])
    n = long(rnmk[1])
    m = long(rnmk[2])
    k = long(rnmk[3])

    output = []

    i = 0
    while i < r:
        prods = map(int, f.readline().split())
        o = []
        for p in prods:
            if p % 5 == 0:
                o.append(5)
            if p % 3 == 0:
                o.append(3)
            if p % 4 == 0:
                o.append(4)
            elif p % 2 == 0:
                o.append(2)

        if len(set(o)) > n:
            o = set(o).pop()
        while len(o) < n:
            o.append(2)

        while len(o) > n:
            o.pop()


        output.append("".join(map(str, o)))
        i += 1

    return "\n" + "\n".join(output)



if __name__ == "__main__":
    solve()