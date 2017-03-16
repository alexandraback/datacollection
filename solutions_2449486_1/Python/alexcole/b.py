import math

fin = open('/Users/alex/Desktop/codejam/b/B-large.in', 'r')
fout = open('/Users/alex/Desktop/codejam/b/B-large.out', 'w')

n =fin.readline().strip()
n = int(n)


def testgrid(data, w, h):
    horzcuts = []
    for dat in data:
        horzcuts.append( max(dat))
    vertcuts = []
    for j in range(h):
        col = [dat[j] for dat in data]
        vertcuts.append( max(col))
    for  x in range(w):
        for y in range(h):
            if data[x][y]< min(horzcuts[x], vertcuts[y]):
                return "Case #"+str(i+1)+": NO\n"
    return "Case #"+str(i+1)+": YES\n"


for i in range(n):
    w, h = fin.readline().strip().split(" ")
    w, h = int(w), int(h)
    data = [[int(k) for k in fin.readline().strip().split(" ")] for j in range(w)]
    answer = testgrid(data, w, h)
    print answer
    fout.write(answer)
        
fin.close()
fout.close()
