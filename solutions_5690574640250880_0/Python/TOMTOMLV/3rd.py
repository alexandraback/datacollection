import math

fIn = open("in.txt", "r")
fOut = open("out.txt", "w")
t = int(fIn.readline())
for i in range(1, t+1):
    r, c, m = [int(x) for x in fIn.readline().split()]
    fOut.write("Case #{:d}:\n".format(i))
    # rows or cols equals 1
    if r == 1:
        fOut.write("c")
        for j in range(2, c+1):
            if j <= c - m:
                fOut.write('.')
            else:
                fOut.write('*')
        fOut.write("\n")
    elif c == 1:
        fOut.write("c\n")
        for j in range(2, r+1):
            if j <= r - m:
                fOut.write('.\n')
            else:
                fOut.write('*\n')
    # special case
    elif (r == 2 or c == 2) and r*c-m == 2:
        fOut.write("Impossible\n")
    # one free
    elif r*c-m == 1:
        fOut.write("c")
        for k in range(2, c+1):
            fOut.write("*")
        fOut.write("\n")
        for j in range(2, r+1):
            for k in range(1, c+1):
                fOut.write("*")
            fOut.write("\n")
    # rows or cols equals 2
    elif r == 2:
        if m % 2 == 1:
            fOut.write("Impossible\n")
        else:
            fOut.write("c")
            for k in range(2, 0, -1):
                for j in range(k, c+1):
                    if j <= c - m/2:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
    elif c == 2:
        if m % 2 == 1:
            fOut.write("Impossible\n")
        else:
            fOut.write("c.\n")
            for k in range(2, r+1):
                if k <= r - m/2:
                    fOut.write("..\n")
                else:
                    fOut.write("**\n")
    # main algorithm
    else:
        free = r * c - m
        if free in [2, 3, 5, 7]:
            fOut.write("Impossible\n")
        else:
            x = int(math.ceil(math.sqrt(free)))
            # rows are limiting
            if r < x:
                #fOut.write("{:d} {:d} r<=x\n".format(r,x))
                cPrim = int(math.ceil(float(free) / r))
                reminder = free % cPrim
                if reminder == 0 and free == cPrim*r:
                    reminder = cPrim
                cut = 0
                if reminder == 1:
                    cut = 1
                    reminder += 1
                # first row
                fOut.write("c")
                for k in range(2, c+1):
                    if k <= cPrim:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
                # all but two last
                for l in range(2, r-1):
                    for k in range(1, c+1):
                        if k <= cPrim:
                            fOut.write(".")
                        else:
                            fOut.write("*")
                    fOut.write("\n")
                # last two
                for k in range(1, c+1):
                    if k <= cPrim - cut:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
                for k in range(1, c+1):
                    if k <= reminder:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
            # cols are limiting
            elif c < x:
                #fOut.write("c<=x\n")
                rPrim = int(math.ceil(float(free) / c))
                reminder = free % c
                if reminder == 0 and free == c*rPrim:
                    reminder = c
                cut = 0
                if reminder == 1:
                    cut = 1
                    reminder += 1
                # first row
                fOut.write("c")
                for k in range(2, c+1):
                    fOut.write(".")
                fOut.write("\n")
                # all but two last
                for l in range(2, rPrim-1):
                    for k in range(1, c+1):
                        fOut.write(".")
                    fOut.write("\n")
                # last two
                for k in range(1, c+1):
                    if k <= c - cut:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
                for k in range(1, c+1):
                    if k <= reminder:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
                # empty rows
                for l in range(rPrim+1, r+1):
                    for k in range(1, c+1):
                        fOut.write("*")
                    fOut.write("\n")
            # put as square in corner
            else:
                cPrim = x
                rPrim = int(math.ceil(float(free) / cPrim))
                reminder = free % cPrim
                if reminder == 0 and free == cPrim*rPrim:
                    reminder = cPrim
                cut = 0
                if reminder == 1:
                    cut = 1
                    reminder += 1
                #fOut.write("square {:d} {:d} {:d} {:d}\n".format(x, rPrim, cut, reminder))
                # first row
                fOut.write("c")
                for k in range(2, c+1):
                    if k <= cPrim:
                        fOut.write(".")
                    else:
                        fOut.write("*")
                fOut.write("\n")
                # all but two last
                for l in range(2, rPrim-1):
                    for k in range(1, c+1):
                        if k <= cPrim:
                            fOut.write(".")
                        else:
                            fOut.write("*")
                    fOut.write("\n")
                # last two
                if rPrim > 1:
                    for k in range(1, c+1):
                        if k <= cPrim - cut:
                            fOut.write(".")
                        else:
                            fOut.write("*")
                    fOut.write("\n")
                if rPrim > 2:
                    for k in range(1, c+1):
                        if k <= reminder:
                            fOut.write(".")
                        else:
                            fOut.write("*")
                    fOut.write("\n")
                # empty rows
                for l in range(rPrim+1, r+1):
                    for k in range(1, c+1):
                        fOut.write("*")
                    fOut.write("\n")