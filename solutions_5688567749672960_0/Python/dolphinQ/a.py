
import sys, math
def rs():
    return sys.stdin.readline().strip()
def ri():
    return int(sys.stdin.readline().strip())
def ras():
    return list(sys.stdin.readline().strip())
def rai():
    return map(int,sys.stdin.readline().strip().split())
def raf():
    return map(float,sys.stdin.readline().strip().split())


def easy(cond):

    arr = [0, 10, 29, 138, 337, 1436, 3435, 14434, 34433, 144432, 344431, 1444430, 3444429, 14444428, 34444427, 144444426, 344444425]

    def rdc(ch, l, t):
        count1 = 0
        count2 = 0
        swap = 0
        sc1 = ch[0:t]
        sc2 = ch[t:]
        if sc1 != "1" + "0"*(t-1):
            swap = 1
            count1 = int(sc1[::-1], 10) - 1
        if sc2 != "0"*(l-t-1) + "1":
            count2 = int(sc2, 10) - 1
        return count1 + count2 + swap + 1


    def red(chis):
        ich = int(chis)
        l = len(chis)
        if l == 1:
            return ich
        if ich == 10**(l-1):
            return arr[l-1]
        c = 0
        if chis[l-1] == "0":
            ich = ich - 1
            c += 1
            chis = str(ich)
            l = len(chis)
        if l % 2 == 0:
            return arr[l-1] + rdc(chis, l, l/2) + c
        else:
            res1 = arr[l-1] + rdc(chis, l, l/2) + c
            res2 = arr[l-1] + rdc(chis, l, l/2 + 1) + c
            return min(res1, res2)
    return red(cond)


with open('./A-small-attempt1.in', 'r') as cf:
    T =int(cf.readline().strip())
    for x in xrange(T):
        with open('./easy.resp', 'a') as cr:
            cr.write("Case #%s: %s\n"%((x+1), easy(cf.readline().strip())))


