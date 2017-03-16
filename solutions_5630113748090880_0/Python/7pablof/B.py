f = open('B-small-attempt1.in')
##f = open('B-large.in')
f2 = open('file.txt', 'w')
t = f.readline()
i = 0
x = {}
for a in range(1,2501):
    x[a] = 0
for l in range(int(t)):
    i += 1
    n = int(f.readline())
    r = []
    for a in range(1,2501):
        x[a] = 0
    for j in range(2*n-1):
        for k in f.readline().split():
            x[int(k)] += 1
    for a in range(1,2501):
        if x[a] % 2 != 0:
            r.append(str(a))        
    print("Case #" + str(i) + ": " + " ".join(r),file=f2)
f.close()
f2.close()
