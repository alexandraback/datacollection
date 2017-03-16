# encoding: utf-8

def solve_raw(x, y):
    score = 0
    for xi in x:
        skip = False
        for j in xrange(len(y)):
            if y[j] > xi:
                skip = True
                del y[j]
                break
        if skip:
            continue
        del y[0]
        score += 1
    return score

def solve(x, y):
    score = 0
    while (y):
        if x[0] > y[0]:
            score += 1
            del y[0]
        else:
            del y[-1]
        del x[0]
    return score

fin = open("war.in", "r")
fou = open("war.txt", "w")

n = int(fin.readline())

for c in xrange(n):
    fin.readline() # nothing to do
    x = [float(t)
            for t in fin.readline().strip().split()]
    y = [float(t)
            for t in fin.readline().strip().split()]
    x.sort()
    y.sort()
    
    raw_score = solve_raw(x[:], y[:])
    score = solve(x, y)
    fou.write("Case #" + str(c + 1) + ": " + 
        str(score) + " " + 
        str(raw_score) + "\n")
    
    

fin.close()
fou.close()
