import copy
import math

inp= open('in2.txt', 'r')
inp_list = [x for x in inp.read().split('\n')]

n = int(inp_list.pop(0))
num = set()
f = open("output2.txt", "w")

def to_num(a):
    a = str(a)
    result = set()
    for i in a:
        result.add(i)
    return set(result)

for i in range(n):
    cur_ways = 0
    answer = ""
    sir = list(map(int,inp_list.pop(0).split(" ")))
    ed = sir[0]
    ways = sir[1]
    matr =[]
    for k in range(ed):
        cur = []
        for t in range(ed):
            cur.append(0)
        matr.append(cur)
    # matr[0][ed - 1] = 1
    if(ed > 2):
        for j in range(ed - 1):
            matr[j][j+1] = 1
        cur_ways = 1
    else:
        matr[0][ed - 1] = 1
        cur_ways = 1
    cur1 = 0
    nex = cur1 + 1
    no = False
    while(cur_ways != ways):
            if(cur1 == ed - 2 and cur_ways != ways):
                f.write("Case #" + str(i+1)+":" + " IMPOSSIBLE" + "\n")
                no = True
                break
            if(matr[cur1][nex] != 1):
                matr[cur1][nex] = 1
                cur_ways += 1
            if(nex == ed - 1):
                cur1 += 1
                nex = cur1 + 1
            else:
                nex += 1

    if(no == False):
            f.write("Case #" + str(i+1) +":" + " POSSIBLE" + "\n")
            for k in range(ed):
                # t = "".join(math[k])
                g1 = str(map(lambda a, x: a + str(x), matr[k]))
                gg = ""
                for ff in matr[k]:
                    gg = gg + str(ff)
                f.write(gg + "\n")

inp.close()
f.close()
