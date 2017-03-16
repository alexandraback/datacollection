import string
import sys
import math

MOD = 1000000007

def simp(ist):
    inew=[]
    for p in ist:
        s = ''
        c = 0
        for i in p:
            if i != c:
                c = i
                s = s+i
        inew.append(s)
    return inew

def conct(inst):
    global connect

    ctx = inst[:]
    for p in inst:
        l = p[0]
        b = True
        for s in p:
            if s != l:
                b = False
                break
        if b: ctx.remove(p)

    ctx.sort()
    connect.sort()
    if (ctx != connect):
        print ctx, connect

    connect = ctx[:]

    c = True
    while c:
        c = False
        i = 0
        for i in xrange(len(connect)):
            p1 = connect[i]
            for j in xrange(i+1,len(connect)):
                p2 = connect[j]
                if p1[0] == p2[-1]:
                    if p1[-1] == p2[0]: return -1
                    l = p2 + p1
                elif p1[-1] == p2[0]:
                    if p1[0] == p2[-1]: return -1
                    l = p1 + p2
                else: continue
                connect.remove(p1)
                connect.remove(p2)
                connect.append(l)
                c = True
                break
            if c: break

    for p in connect:
        if len(p) > 1 and p[0] == p[-1]: return 0

    print ctx, connect
    return connect

def deal(lst, l):
    global connect
    global full
    if (len(lst) <= 0): return 1

    alll = []
    for p in lst:
        b = True
        for s in p:
            if s != l:
                b = False
                break
        if b: alll.append(p)

    for p in alll:
        lst.remove(p)

    num = math.factorial(len(alll)) % MOD

    if (len(lst) >= 3): return 0
    if (len(lst) == 0):
        full += 1
        return num

    # consecutive
    for p in lst:
        seen = 0
        for s in p:
            if s == l and seen == 0: seen = 1
            elif s == l and seen == 1: continue
            elif seen == 1: seen = 2
            elif s == l and seen == 2:
                if len(lst) == 1 and not alll: return 1
                else: return 0
    #print "bwarf ",l,lst,alll

    alldeb = 0
    allend = 0
    for p in lst:
        if p[0] == l: alldeb += 1
        if p[-1] == l: allend += 1

    if len(lst) == 1:
        e = lst[0]
        if alldeb == 1 or allend == 1:
            if not e in connect: connect.append(e)
            return num % MOD
        # deb = end = 0
        if alll: return 0
        if not e in connect: connect.append(e)
        return 1

    if alldeb + allend != len(lst) or alldeb > 1 or allend > 1: return 0

    for pp in lst:
        if not pp in connect:
            connect.append(pp)
    return num % MOD

def check(inst):
    for p in inst:
        l = []
        c = -1
        for w in p:
            if w == c: continue
            c = w
            if c in l: return False
            l.append(c)

    return True

def solve(inst):
    global connect
    global full
    full = 0
    connect = []
    num = 1

    if not check(inst): return 0

    for l in string.lowercase:
        lst = []
        for p in inst:
            if l in p: lst.append(p)
        nm = deal(lst,l)
        #print inst, lst, l, nm
        #print connect
        if (nm <= 0): return 0
        num = (num*nm) % MOD

    #print connect
    ret = conct(inst)
    if ret == -1: return 0
    #print connect
    f = full + len(connect)
    nm = math.factorial(f) % MOD

    return (num*nm) % MOD

def main():
    #inp = open('exB', 'r')
    #out = sys.stdout
    inp = open('B-large.in', 'r')
    out = open('B-large.out', 'w')
    num_case = int(inp.readline())
    for i in xrange(num_case):
        n = int(inp.readline())
        line = inp.readline()
        instance = line.split()
        #instance = simp(instance)
        #print instance
        out.write("Case #"+str(i+1)+": "+str(solve(instance))+'\n')
    inp.close()
    out.close()

if __name__ == "__main__":
    main()
