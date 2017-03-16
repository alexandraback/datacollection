from __future__ import print_function

outFile = open("minesweeper.out", "w")

#lines = list(open("minesweeper.in"))
lines = list(open("C-small-attempt1.in"))
#lines = list(open("C-large.in"))
testCount = int(lines.pop(0))

def seek(solution, marked):
    print("seeking ", solution, marked)
    remaining = nonMined - marked
    if remaining == 0:
       return solution if solution[-1] > 1 else None
    else:
        remainingRows = rows - len(solution)
        if remainingRows * solution[-1] < remaining:
            return None
        for i in range(min(solution[-1], remaining),1,-1):
            result = seek(solution+[i],marked+i)
            if result != None:
                return result
    return None



for test in range(1, testCount+1):
    print("Case #{}:".format(test))
    rows, cols, mines = [int(x) for x in str.split(lines.pop(0))]
    sq = rows*cols
    #print(rows, cols, sq, mines)

    text = ""
    if mines >= sq:
        text = "Impossible\n"
    if mines == sq-1:
        vals = []
        for i in range(rows-1):
            vals += ["*"] * cols
            vals += ["\n"]
        vals += ["*"] * (cols-1)
        vals += ["c\n"]
        text = "".join(vals)
    elif rows == 1:
        vals = ["*"] * mines
        vals += ["."] * (cols-mines-1)
        vals += ["c\n"]
        text = "".join(vals)
    elif cols == 1:
        vals = ["*\n"] * mines
        vals += [".\n"] * (rows-mines-1)
        vals += ["c\n"]
        text = "".join(vals)
    elif mines <= sq-4:
        vals = []
        #mined = 0
        #for i in range(rows):
        #    for j in range(cols):
        #        if mined < mines and (i < rows-2 or j < cols-2):
        #            vals += ["*"]
        #            mined += 1
        #        else:
        #            vals += ["."]
        #    vals += ["\n"]
        #vals[-2:] = ["c\n"]
        #text = "".join(vals)
        nonMined = rows*cols - mines
        for i in range(min(cols,int(nonMined/2)),1,-1):
            result = seek([i]*2,i*2)
            if result != None:
                print(result)
                break
        if result != None:
            for i in result:
                vals += ["."]*i
                vals += ["*"]*(cols-i)
                vals += ["\n"]
            for i in range(rows-len(result)):
                vals += ["*"]*cols
                vals += ["\n"]
            vals[0] = "c"
            text = "".join(vals)
        else:
            text = "Impossible\n"
    else:
        text = "Impossible\n"

    print(text)
    outFile.write("Case #{}:\n".format(test))
    outFile.write(text)

outFile.close()
