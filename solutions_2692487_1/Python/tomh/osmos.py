from copy import copy

def do(c,motes):
    while motes!=[] and c>min(motes):
        c+=min(motes)
        motes.remove(min(motes))
    return c,motes

def solve(c,motes):
    bestSolution = len(motes)
    curSol = 0
    while True:
        c, motes = do(c, motes)
        if curSol+len(motes)<bestSolution:
            bestSolution = curSol+len(motes)
        if motes==[]:
            break
        if (c-1)==0:
            curSol=100000000
            break
        motes.append(c-1)
        curSol+=1
    if curSol<bestSolution:
        bestSolution=curSol
    return bestSolution

with open('input.txt') as f:
    lines = f.readlines()
tcases = int(lines[0])

with open('output.txt','w') as f:
    for case in range(0,tcases):
        line1 = lines[case*2+1]
        line2 = lines[case*2+2]
        motes = map(int,line2.split(" "))
        c = map(int,line1.split(" "))[0]
        total = solve(c,motes)
        f.write("Case #" + str(case+1) + ": " + str(total) + '\n')