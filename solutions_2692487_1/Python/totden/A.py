f = open("A-large.in", "r")
f1 = open("output.txt", "w")

test = int(f.readline())


def tinh(x, y):
    cnt = 0
    while x <= y:
        x = 2 * x - 1
        cnt = cnt + 1
    return (cnt, x + y)

def calculate(amote, mote, n):
    if amote == 1: return n
    mote.sort()
    res = 0
    while n>0:
        if amote <= mote[0]: break
        amote += mote[0]
        del mote[0]
        n = n-1
    f = {}
    a = {}
    f[(0,1)] = 0
    f[(0,2)] = 0
    a[(0,1)] = amote
    a[(0,2)] = amote
    for i in range(n):
       # print i, amote, mote[i]
        if f[(i,1)] < f[(i,2)]:
            f[(i+1,1)] = f[(i,1)]+1
            a[(i+1,1)] = a[(i,1)]
        else:
            if f[(i,1)] == f[(i,2)]:
                f[(i+1,1)] = f[(i,1)] + 1
                if a[(i,1)] > a[(i,2)]:
                    a[(i+1,1)] = a[(i,1)]
                else: a[(i+1,1)] = a[(i,2)]
            else:
                f[(i+1,1)] = f[(i,2)]+1
                a[(i+1,1)] = a[(i,2)]
                
        (cal1, numb1) = tinh(a[(i,1)], mote[i])
        (cal2, numb2) = tinh(a[(i,2)], mote[i])
        if f[(i,1)] + cal1 < f[(i,2)] + cal2:
            f[(i+1,2)] = f[(i,1)] + cal1
            a[(i+1,2)] = numb1
        else:
            if f[(i,1)] + cal1 == f[(i,2)] + cal2:
                f[(i+1),2] = f[(i,1)] + cal1
                if numb1 > numb2:
                    a[(i+1,2)] = numb1
                else: a[(i+1,2)] = numb2
            else:
                f[(i+1,2)] = f[(i,2)] + cal2
                a[(i+1,2)] = numb2
   # print f[(n,1)], f[(n,2)]
    return min(f[(n,1)], f[(n,2)])

for i in range(test):
    (amote, n) = f.readline().split()
    mote = []
    for x in f.readline().split():
        mote.append(int(x))
    print >> f1, "Case #%d:" %(i+1), calculate(int(amote), mote, int(n))

f1.close()
    
