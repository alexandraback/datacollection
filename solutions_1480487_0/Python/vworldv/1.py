import numpy as np

def solveCaseArr(scores):
    scores0 = scores
    scores = np.array(list(scores), dtype=float)
    s = sum(scores)
    needed = 2*s / float(len(scores))
    bad = (scores > needed)
    good = (scores <= needed)
    scores_good = scores[good]
    needed_good = (s + sum(scores_good)) / float(len(scores_good))
    result_good = 100 * (needed_good - scores_good) / s
    result = np.zeros_like(scores)
    result[good] = result_good
##    result[bad] = 0
##    result = 100 * (needed - scores) / s
    print scores0, result, scores + sum(scores) * result * 0.01
    return result

def solveCase(scores):
    return " ".join([str(i) for i in solveCaseArr(scores)])

def parseSolveCase(s):
    l = parseCase(s)
    return solveCase(l[1:])

def parseCase(s):
    return [int(i) for i in s.split(" ")]

def solve(fil):
    fout = open("out.txt", mode = "wb")
    lNum = 0
    with open(fil) as f:
        for line in f:
            if lNum > 0:
                fout.write("Case #%d: %s\r\n" \
                           % (lNum, parseSolveCase(line)))
            lNum += 1
    fout.close()
