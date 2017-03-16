import math

fin = open('input.in', 'r')
output = open('output.txt','w')

loops = int(fin.readline())

for x in range(loops):
    r,c,w = fin.readline().split()
    print(r + c + w)
    r = int(r)
    c = int(c)
    w = int(w)
    if w != r*c:
        output.write("Case #" +str(x + 1)+ ": " + str(math.ceil(c/w) * r + (w - 1)) + "\n")
    else:
        output.write("Case #" + str(x+1) + ": " + str(w) + "\n")

output.close()
        
