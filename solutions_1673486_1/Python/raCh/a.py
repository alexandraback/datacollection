def estimate(pright, done, remaining):
    exp = pright * (remaining + 1) + (1-pright)*(remaining+1 + done + remaining+1)
    return exp    


f = open("A-large.in")
w = open("A-large.out.0.txt", 'w')
T = int(f.readline().strip())
for t in range(1, T+1):
    line = f.readline().strip()
    values = line.split(" ")
    A = values[0]
    B = values[1]
    a = int(A)
    b = int(B)
    p = []
    pmatrix = []
    smatrix = []
    exps = []
    exps.append(1+b+1)
    pline = f.readline().strip()
    ps = pline.split(" ")
    base = 1
    pmatrix.append((1.0, 0.0))
    for eachp in ps:
        pi = float(eachp)
        p.append(pi)
        pright = base*pi
        pwrong = base*(1-pi) + (1-base)
        pmatrix.append((pright,pwrong))
        base = pright
    for i in range(a, -1, -1):
        rightkey = i + i + (b-a) + 1
        wrongkey = i + i + (b-a) + 1 + b + 1
        smatrix.append((rightkey, wrongkey))
    l = len(pmatrix)
    for i in range(0, l):
        rexp = pmatrix[i][0] * smatrix[i][0]
        wexp = pmatrix[i][1] * smatrix[i][1]
        exp = rexp + wexp
        exps.append(exp)
        
    print "Case #" + str(t) + ": " + str(float(min(exps)))
    w.write("Case #" + str(t) + ": " + str(float(min(exps))) + "\n")
f.close()
w.close()
