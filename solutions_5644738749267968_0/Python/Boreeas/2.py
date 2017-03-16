#default gcj in file reader
#Boreeas, 7/3/2012
fin = open("in")
fout = open("out", "w")
case = 0

def wrt(out):
    global case
    case += 1
    fout.write("Case #" + str(case) + ": " + str(out) + "\n")

def partition(nao, ken):
    i_n = 0
    i_k = 0
    g = []
    b = []
    while i_n < len(nao):
        if nao[i_n] > ken[i_k]:
            g.append((nao[i_n], ken[i_k]))
            i_k += 1
        else:
            b.append(nao[i_n])
        i_n += 1
    return g #zip(b, ken[i_k:][::-1]))

def nice(nao, ken):
    return partition(ken, nao)
    

fin.readline()  #skip number-of-cases
while 1:
    line = fin.readline().rstrip()
    if not line:
        break
    # Hook here
    n = int(line)
    nao = [float(x) for x in fin.readline().rstrip().split()]
    ken = [float(x) for x in fin.readline().rstrip().split()]

    nao.sort()
    ken.sort()
    points_true = n - len(nice(nao, ken))
    points_cheat = len(partition(nao, ken))
    wrt(str(points_cheat) + " " + str(points_true))


#release handles
fin.close()
fout.close()
