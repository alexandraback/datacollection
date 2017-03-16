def getvalue(line):
    res = []
    for i in range(len(line)-1):
        if (line[i] == '+'):
            res.append(1)
        else:
            res.append(-1)
    return res

def parse(path):
    files = open(path)
    files.readline()
    content = files.readlines()
    for i in range(len(content)):
        content[i] = getvalue(content[i])
    return content

def flip(pancakes, i):
    res = []
    for k in range(i+1):
        res.append(-pancakes[i-k])
    for k in range(i+1, len(pancakes)):
        res.append(pancakes[k])
    return res

def moves(pancakes):
    steps = 0
    bottom = len(pancakes)-1
    while (bottom != 0):
        if (pancakes[bottom] == 1):
            bottom -= 1
            continue
        steps += 1
        if (pancakes[0] == -1):
            pancakes = flip(pancakes, bottom)
        else:
            i = bottom
            while (pancakes[i] == -1):
                i -= 1
            pancakes = flip(pancakes, i)
    if (pancakes[bottom] == -1):
        steps += 1
    return steps

def output():
    data = parse("B-small-attempt0.in")
    L = []
    for i in range(len(data)):
        L.append("Case #"+str(i+1)+": "+str(moves(data[i]))+"\n")
    output=(open("outputpancakes.out","w"))
    output.writelines(L)

output()



