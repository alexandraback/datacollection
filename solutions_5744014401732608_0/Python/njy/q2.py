inp = open(r"F:\Nir\Downloads\B-small-attempt0.in",'r')
out = open(r"F:\Nir\Downloads\njy\q2.out", 'w')
l = inp.readlines()

a = []
t = int(l[0])
idx = 1
for i in range(t):
    b,m = [int(num) for num in l[idx].split(" ")]
    idx += 1

    r = [2**(b-k-1) for k in range(b)]
    con = [False for k in range(b+1)]
    #specific case
    con[b] = True
    m -= 1

    for i in range(2,b):
        if m >= r[i]:
            con[i] = True
            m -= r[i]
    
    s = ""
    if m == 0:
        s += "POSSIBLE\n"
        for i in range(1,b+1):
            if con[i]:
                s += "1"
            else:
                s += "0"
        s += "\n"
        for i in range(2,b+1):
            for j in range(1,b+1):
                if j > i:
                    s += "1"
                else:
                    s += "0"
            s += "\n"
    else:
        s = "IMPOSSIBLE\n"

    a.append(s)

for i in range(t):
    out.write("Case #{0}: {1}".format(i+1,a[i]))
out.close()