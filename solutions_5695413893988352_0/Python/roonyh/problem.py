fo = open("sm.in", "r")

T = int(fo.readline())

for zz in range(T):
    c, j = fo.readline().rstrip().split()
    c = [i for i in c]
    j = [i for i in j]


    def solve(c, j):
        l = len(c)
        lg = c
        sm = j
        lgf = False
        for i in xrange(l):
            if(not lgf):
                if(c[i] == '?' and j[i] == '?'):
                    c[i] = '0'
                    j[i] = '0'
                    continue

                if(c[i] == '?' and j[i] != '?'):
                    c[i] = j[i]
                    continue

                if(c[i] != '?' and j[i] == '?'):
                    j[i] = c[i]
                    continue

                if(c[i] != '?' and j[i] != '?'):
                    if int(j[i]) > int(c[i]):
                        lg = j
                        sm = c
                        lgf = True
                        continue
                    if int(j[i]) < int(c[i]):
                        lg = c
                        sm = j
                        lgf = True
                        continue


            if(lg[i] == '?'):
                lg[i] = '0'
            if(sm[i] == '?'):
                sm[i] = '9'

    need = False

    for i in xrange(len(c)):
            if(c[i] == '?' and j[i] == '?'):
                need = True
                cl = c[:]
                jl = j[:]
                cl[i] = '0'
                jl[i] = '1'
                ch = c[:]
                jh = j[:]
                ch[i] = '1'
                jh[i] = '0'
                break


            if(c[i] == '?' and j[i] != '?'):
                need = True
                cl = c[:]
                jl = j[:]
                if(j[i]>0):
                    cl[i] = str(int(j[i])-1)
                ch = c[:]
                jh = j[:]
                if(j[i]<9):
                    ch[i] = str(int(j[i])+1)
                break

            if(c[i] != '?' and j[i] == '?'):
                need = True
                cl = c[:]
                jl = j[:]
                if(c[i]>0):
                    jl[i] = str(int(c[i])-1)
                ch = c[:]
                jh = j[:]

                if(c[i]<9):
                    jh[i] = str(int(c[i])+1)
                break


            if(c[i] == j[i]):
                continue

            if(c[i] != '?' and j[i] != '?'):
                break

    if(need):
        solve(cl, jl)
        solve(ch, jh)
        solve(c, j)
        clss, jlss = int("".join(cl)), int("".join(jl))
        chss, jhss = int("".join(ch)), int("".join(jh))
        css, jss = int("".join(c)), int("".join(j))
        min = abs(css-jss)
        if(abs(clss-jlss) < abs(css-jss)):
            min = abs(clss-jlss)
            c, j = cl, jl
        if(abs(chss-jhss) < min):
            c, j = ch, jh

    else:
        solve(c, j)

    print "Case #%d: %s %s" % (zz+1, "".join(c), "".join(j))