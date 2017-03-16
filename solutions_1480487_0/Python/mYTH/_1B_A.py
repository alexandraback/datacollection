#

i = open("A-small-attempt3.in", "r")
o = open("A-small.out", "w")

T = int(i.readline())

for c in range(1, T + 1):
    args = map(int, i.readline().replace('\n','').split(' '))
    
    N = args[0]
    sN = args[1:]
    X = sum(sN)

    ans = []
    for k in range(N):
        val = 0
        for l in range(N):
            if k != l:
                val += sN[l] - sN[k]
        val = 1 + float(val)/X
        res = val*100/N
        if res > 0:
            ans.append(res)
        else:
            ans.append(0.0)   

    # do stuff
    o.write("Case #{0}: {1}\n".format(c, ' '.join(map(str, ans))))

i.close()
o.close()