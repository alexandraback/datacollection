def password(l, x):

    A = int(l[0])
    B = int(l[1])

    prob =  map(float, fin.readline().split())

    min = (B + 2) * 1.0
    product = 1
    
    for i in range(A):
        product *= prob[i]
        expect_no = product * (A + B - 2 * i - 1) + (1 - product) * (A + 2 * B - 2 *i)
        if expect_no < min:
            min = expect_no

    min = "%0.6f"%(min)
    string = str(min)

    fout = open("output.txt", "a")
    fout.write("Case #" + str(x) + ": ")
    fout.write(str(min))
    fout.write("\n")
    fout.close()
        

fin = open("A-small-attempt0.in", "r")

n = int(fin.readline())
for i in range(n):
    line = fin.readline()
    l = line.split()
    password(l, i+1)


