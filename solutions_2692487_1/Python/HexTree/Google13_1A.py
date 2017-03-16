f = open("dataIn.txt", 'r')
g = open("dataOut.txt", 'w')

t = int(f.readline())

def moves(a, motes):
    if motes == []:
        return 0
    elif a > motes[0]:
        return moves(a+motes[0], motes[1:])   
    else:
        m = len(motes)
        k = 0
        b = a
        if b == 1:
            return m
        while b <= motes[0]:
            b = 2*b - 1
            k += 1
        if k < m:
            return min(k + moves(b + motes[0], motes[1:]), 1 + moves(a, motes[1:]))
        else:
            return m

for i in range(t):
    line = f.readline()
    (a, n) = [int(x) for x in line.split()]
    line = f.readline()
    motes = [int(x) for x in line.split()]
    motes.sort()
    result = str(moves(a, motes))
    g.write("Case #" + str(i+1) + ": " + result + '\n')
    
f.close()
g.close()

print "Done."
