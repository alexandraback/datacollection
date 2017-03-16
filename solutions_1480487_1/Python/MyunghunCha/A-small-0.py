fin=open("A-large-0.in",'r')
#fin=open("A-test.in",'r')
fout= open("A-large-0.out",'w')

for i in range(int(fin.readline())):
    inp = fin.readline().split()
    n = int(inp[0])
    s = map(int,inp[1:])
    ss = sum(s)

    s2 = s[:]

    P = T = 0
    s2.sort()
    s2.reverse()

    for k in s2:
        if 2*ss-(n-T)*k -P < 0:
            P += k
            T += 1
        else:
            break

    for j in range(n):
        k = 2.0*ss / (n-1)

    fout.write("Case #%d: "%(i+1) + " ".join(map(str,[max(0,(100.0 * (2*ss - (n-T)*s[j] - P)) / ((n-T) * ss)) for j in range(n)]))+"\n")

fin.close()
fout.close()
    
