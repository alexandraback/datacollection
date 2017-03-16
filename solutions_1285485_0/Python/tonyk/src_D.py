import math

#fn = 'D-small-attempt0'
fn = 'D-small-attempt1'
#fn = 'sample'

inp = open(fn + '.in', 'r')
out = open(fn + '.out', 'w')

n = int(inp.readline())
for i in range(n):
    line = inp.readline()
    spl = line.split()

    h = int(spl[0])
    w = int(spl[1])
    d = int(spl[2])

    hall = []
    me = []
    for j in range(h):
        line = inp.readline()
        hall.append(line)
        if me == []:
            for k in range(w):
                if line[k] == 'X':
                    me = [j, k]
                    break
            

    xg = 0.5
    xd = h - 1.5
    yl = 0.5
    yd = w - 1.5

    lijevo = False
    desno = False
    gore = False
    dolje = False

    mm = []
    mv = []
    vm = []
    vv = []

    sol = 0
    lista = [me]
    l2 = [me]
    while len(lista) > 0:
        tmp = lista.pop()
        dn = math.sqrt((tmp[0] - me[0])**2 + (tmp[1] - me[1])**2)
        
        if dn <= d:

            if dn > 0:
                if tmp[0] == me[0]:
                    if tmp[1] < me[1]:
                        if not lijevo:
                            sol += 1
                            lijevo = True
                    if tmp[1] > me[1]:
                        if not desno:
                            sol += 1
                            desno = True
                elif tmp[1] == me[1]:
                    if tmp[0] < me[0]:
                        if not gore:
                            sol += 1
                            gore = True
                    if tmp[0] > me[0]:
                        if not dolje:
                            sol += 1
                            dolje = True
                elif tmp[0] < me[0] and tmp[1] < me[1]:
                    nema = True
                    for tt in range(len(mm)):
                        if (mm[tt][0] - me[0]) * (tmp[1] - me[1]) == (tmp[0] - me[0]) * (mm[tt][1] - me[1]):
                            nema = False
                            break
                    if nema:
                        sol += 1
                        mm.append(tmp)
                elif tmp[0] < me[0] and tmp[1] > me[1]:
                    nema = True
                    for tt in range(len(mv)):
                        if (mv[tt][0] - me[0]) * (tmp[1] - me[1]) == (tmp[0] - me[0]) * (mv[tt][1] - me[1]):
                            nema = False
                            break
                    if nema:
                        sol += 1
                        mv.append(tmp)
                elif tmp[0] > me[0] and tmp[1] < me[1]:
                    nema = True
                    for tt in range(len(vm)):
                        if (vm[tt][0] - me[0]) * (tmp[1] - me[1]) == (tmp[0] - me[0]) * (vm[tt][1] - me[1]):
                            nema = False
                            break
                    if nema:
                        sol += 1
                        vm.append(tmp)
                elif tmp[0] > me[0] and tmp[1] > me[1]:
                    nema = True
                    for tt in range(len(vv)):
                        if (vv[tt][0] - me[0]) * (tmp[1] - me[1]) == (tmp[0] - me[0]) * (vv[tt][1] - me[1]):
                            nema = False
                            break
                    if nema:
                        sol += 1
                        vv.append(tmp)
                        
            
            
            xs = []
            ys = []
            if tmp[0] > xg:
                xs.append(round(tmp[0] - 2*(tmp[0] - xg)))
            if tmp[0] < xd:
                xs.append(round(tmp[0] + 2*(xd - tmp[0])))
            if tmp[1] > yl:
                ys.append(round(tmp[1] - 2*(tmp[1] - yl)))
            if tmp[1] < yd:
                ys.append(round(tmp[1] + 2*(yd - tmp[1])))

            for xi in range(len(xs)):
                if not [xs[xi], tmp[1]] in l2:
                    lista.append([xs[xi], tmp[1]])
                    l2.append([xs[xi], tmp[1]])
            for yi in range(len(ys)):
                if not [tmp[0], ys[yi]] in l2:
                    lista.append([tmp[0], ys[yi]])
                    l2.append([tmp[0], ys[yi]])
                    

            
    out.writelines('Case #' + str(i+1) + ': ' + str(sol) + '\n')

inp.close()
out.close()
