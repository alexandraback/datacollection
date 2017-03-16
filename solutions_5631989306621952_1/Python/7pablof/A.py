##f = open('A-small-attempt0.in')
f = open('A-large.in')
f2 = open('file.txt','w')
T = f.readline()
i = 0
for l in f:
    i += 1
    r = ""
    for a in l:
        if r=="":
            r=a
        elif a>=r[0]:
            r=a+r
        else:
            r=r+a
    print("Case #" + str(i) + ": " + r,file=f2)
f.close()
f2.close()
