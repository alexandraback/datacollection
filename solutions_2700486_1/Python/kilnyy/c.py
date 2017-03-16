c = [[] for i in range(1000)]

for i in range(1000):
    for j in range(i+1):
        if j==0 or i==j :
            c[i].append(1)
        else :
            c[i].append(c[i-1][j-1] + c[i-1][j])

d = []
d.append(1)
dn = 1
tmp = 1
while (d[dn-1] <= 100000):
    tmp += 4
    d.append(d[dn-1] + tmp)
    dn += 1



with open("c.in","r") as in_file:
    zu = 0
    for row in in_file:
        if len(row.split()) > 1:
            ans=0
            zu=zu+1
            nn, xx, yy = row.split()
            n = int(nn)
            x = abs(int(xx))
            y = int(yy)
            dis = (x + y) / 2
            cn = 0

            for i in range(dn) :
                if n < d[i] :
                    cn = i-1
                    break

            if dis <= cn :
                ans = 1
            elif dis > cn + 1 :
                ans = 0
            else :
                cha = (d[cn+1] - d[cn] - 1) / 2
                have = n - d[cn]
                for l in range(have+1):
                    ttt = l
                    r = have - l
                    if l > cha :
                        r += l - cha
                        l = cha
                    if r > cha :
                        l += r - cha
                        r = cha
                    if l > y :
                        ans += float(c[have][ttt]) / 2**have

            print "Case #%d: %f"%(zu, ans)
