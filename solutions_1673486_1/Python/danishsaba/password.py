def password(L1, L2, n):
    A = int(L1[0])
    B = int(L1[1])
    minm = (B+2)*1.0
    p = 1
    for i in range(A):
        p *= float(L2[i])
        expt = p*(A+B-2*i-1)+(1-p)*(A+2*B-2*i)
        if expt < minm:
            minm = expt
        sol = "%.6f"%(minm)
    file2 = open("output.txt", 'a')
    line1 = "Case #"+str(n)+": "
    file2.write(line1)
    file2.write(sol+"\n")
    file2.close()
        


file1 = open("A-large.in", 'r')
n = int(file1.readline())
for i in range(n):
    l1 = file1.readline().split()
    l2 = file1.readline().split()
    password(l1, l2, i+1)
