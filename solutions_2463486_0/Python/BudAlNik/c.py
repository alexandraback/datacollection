inp = open("input.txt", "r")
outp = open("output.txt", "w")

mas = []
for i in xrange(1, 7):
    for j in xrange(10 ** (i - 1), 10 ** i):
        s1 = str(j)
        s2 = s1[-1::-1]
        s3 = str(int(s1 + s2) ** 2)
        if(s3 == s3[-1::-1]):
            mas.append(int(s3))
        s3 = str(int(s1 + s2[1: ]) ** 2)
        if(s3 == s3[-1::-1]):
            mas.append(int(s3))
    print("Finished the bust small palindromes lengths " + str(i * 2))
        

mas.sort()
print mas


t = int(inp.readline().strip())

le = len(mas)
for i in xrange(t):
    a, b = map(int, inp.readline().strip().split(" "))
    l, r = -1, le - 1
    while(r - l > 1):
        m = (r + l) / 2
        if(mas[m] >= a):
            r = m
        else:
            l = m
    mema = r
    l, r = 0, le
    while(r - l > 1):
        m = (r + l) / 2
        if(mas[m] <= b):
            l = m
        else:
            r = m
    memb = l
    print mema, memb
    outp.write("Case #" + str(i + 1) + ": " + str(max(memb - mema + 1, 0)) + "\n")

inp.close()
outp.close()

