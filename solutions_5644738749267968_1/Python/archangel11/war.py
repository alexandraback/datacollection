import copy

def solve(f):
    n = int(f.readline())

    naomi = sorted(map(float, f.readline().split()))
    ken = sorted(map(float, f.readline().split()))

    #raw_input()
    #print n
    #print naomi
    #print ken

    normal = n
    kentop = n-1
    kenbot = 0
    for i in reversed(xrange(n)):
        if ken[kentop] > naomi[i]:
            normal -= 1
            kentop -= 1
        else:
            kenbot += 1


    deceit = 0
    removed = 0
    dn = copy.copy(naomi)
    dk = copy.copy(ken)

    while removed < n:
        lessthanmin = 0
        for b in dn:
            if b < dk[0]:
                lessthanmin += 1
            else:
                break

        greaterthanmax = 0
        for b in reversed(dk):
            if b > dn[len(dn)-1]:
                greaterthanmax += 1
            else:
                break

        toremove = max(lessthanmin, greaterthanmax)
        for i in range(toremove):
            #print i
            #print dn
            del dn[0]
            del dk[-1]
            removed += 1

        while removed < n and dn[0] > dk[0]:
            #print dn[0], dk[0]
            del dn[0]
            del dk[0]
            removed += 1
            deceit += 1



    return "{} {}".format(deceit, normal)

