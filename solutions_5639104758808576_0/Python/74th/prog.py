import sys

DEBUG = True
DEBUG = False

qNum = int(sys.stdin.readline())
def debug(s1,s2):
    if DEBUG :
        print(str(s1) + ":" + str(s2))

def ans(q):
    a = 0

    l = sys.stdin.readline().strip().split(" ")
    smax = int(l[0])
    sl = l[1]
    shyness = -1
    stand = 0
    friend = 0
    for ss in sl :
        shyness += 1
        manNum = int(ss)

        debug("shyness",shyness)
        debug("manNum",manNum)

        if manNum == 0 :
            continue
        if shyness > stand :
            friend += shyness - stand
            stand = shyness
            stand += manNum
        else :
            stand += manNum
        debug("stand",stand)
        debug("friend",friend)

    print("Case #" + str(q) + ": " + str(friend))
    pass

for q in range(qNum):
    ans(q+1)
