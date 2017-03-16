f = open("dataIn.txt", 'r')
g = open("dataOut.txt", 'w')

def trim(mat, i, h):
    for j in range(len(mat[0])):
        mat[i][j] = min(mat[i][j], h)
    return mat
t = int(f.readline())

for i in range(t):
    n, m = (int(x) for x in f.readline().split())
    model = []
    for j in range(n):
        model.append([int(x) for x in f.readline().split()])
    clone = [[100 for x in range(m)] for x in range(n)]

    for j in range(n):
        clone = trim(clone, j, max(model[j]))

    modelTranspose = map(list, zip(*model))
    cloneTranspose = map(list, zip(*clone))

    for j in range(m):
        cloneTranspose = trim(cloneTranspose, j, max(modelTranspose[j]))

    result = "YES"
    if modelTranspose != cloneTranspose:
        result = "NO"
    
    g.write("Case #" + str(i+1) + ": " + result + '\n')
    
f.close()
g.close()

print "Done."
