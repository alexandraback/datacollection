f = open('A-small-attempt1.in')
fout = open('A-small-attempt1.out',mode = 'w')
numtests = int(f.readline())
for x in range(1,numtests+1):
    trash,inp = f.readline().split(' ')
    inp = inp[:-1]
    l = list(map(int,list(inp)))
    m = 0
    currnecc = 0
    for i in l:
        currnecc += 1
        currnecc -= i
        m = max(m,currnecc)
    fout.write("Case #"+str(x)+": "+str(m)+"\n")
f.close()
fout.close()
