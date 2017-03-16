def getvalue(line):
    res = line.split(' ')
    for i in range(len(res)):
        res[i] = int(res[i])
    return res

def parse(path):
    files = open(path)
    files.readline()
    content = files.readlines()
    for i in range(len(content)):
        content[i] = getvalue(content[i])
    return content

def fract(L):
    k,c,s = L[0], L[1], L[2]
    if (k > s*c):
        return " IMPOSSIBLE"
    L = ""
    i = 0
    while(i < k):
        aux = 1
        for ind in range(c):
            if (i+ind)>=k :
                break
            aux += (i+ind)*k**(min(k,c)-ind-1)
        L+= " "+str(aux)
        i+=c
    return L


def output():
    data = parse("D-large.in")
    L = []
    for i in range(len(data)):
        L.append("Case #"+str(i+1)+":"+fract(data[i])+"\n")
    output=(open("outputfrac.out","w"))
    output.writelines(L)

output()
