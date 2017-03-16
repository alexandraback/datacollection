import math
def binary(x):
    binaryx = ""
    if x==0:
        return "0"
    w=x
    y = (math.log(x, 2) // 1) + 1
    for p in range (int(y), h-1):
        binaryx = binaryx + "0"
    while y!=0:
        if w < 2**(y-1):
            binaryx = binaryx + "0"
        else:
            binaryx = binaryx + "1"
            w = w - (2**(y-1))
        y = y-1
    return binaryx
def split(c):
    data = list()
    finish = False
    d = -1
    e = 0
    while finish == False:
        d = d+1
        e = e+1
        if c[d] == " ":
            data.append(c[d-e+1:d])
            c = c[:d] + "," + c[d:]
            d = d+1
            e = 0
        if d == len(c)-1:
            finish = True
    data.append(c[len(c)-e:])
    return data
with open("B-small2016R1C4.in") as z:
    a = z.readline()
    for b in range (0, int(a)):
        v = z.readline()
        f = split(v)
        for g in range (0,2):
            f[g] = int(f[g])
        special = False
        h = f[0]
        i = f[1]
        if i>2**(h-2):
            print("Case #" + str(b+1) + ": " + "IMPOSSIBLE")
            continue
        elif i == 2**(h-2):
            special = True
            print("Case #" + str(b+1) + ": " + "POSSIBLE")
            i = i-1
        else:
            print("Case #" + str(b+1) + ": " + "POSSIBLE")
        j = binary(i)
        j = list(j)
        if special == True:
            j.append("1")
        else:
            j.append("0")
        for k in range (0,h):
            answer = ''
            for l in range (0,k+1):
                answer = answer + "0"
            for m in range (k+1,h-1):
                answer = answer + "1"
            if k == h-1:
                answer = answer
            else:
                answer = answer + j[h-1-k]
            print(answer)


      
