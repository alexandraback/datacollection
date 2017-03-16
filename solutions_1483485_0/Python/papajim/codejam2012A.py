f = open(r'A-small-attempt0.in', 'r')
g = open(r'outputA.out', 'w')
t = int(f.readline())
alphabet = "abcdefghijklmnopqrstuvwxyz "
googlerese = "ynficwlbkuomxsevzpdrjgthaq "
for i in range(1, t+1):
    g.write("Case #"+str(i)+": ")
    G = f.readline().replace('\n', '')
    s = ''
    for k in G:
        for j in range(len(googlerese)):
            if googlerese[j] == k:
                s+=alphabet[j]
    g.write(s+"\n")
f.close()
g.close()
