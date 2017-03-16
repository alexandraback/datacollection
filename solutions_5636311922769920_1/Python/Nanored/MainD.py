f = open("D-large.in", 'r')
f2 = open("repD.txt", 'w')
t = int(f.readline())
for i in range(1, t+1):
    tab = f.readline().split(" ")
    k = int(tab[0])
    c = int(tab[1])
    s = int(tab[2])
    f2.write("Case #" + str(i) + ":")
    if c*s < k:
        f2.write(" IMPOSSIBLE\n")
    else:
        b = 0
        while b < k:
            n = 0
            for j in range(c):
                b = min(b+1, k)
                n += (b-1) * k ** (c-j-1)
            f2.write(" " + str(n+1))
        f2.write("\n")
f.close()
f2.close()
                
            
