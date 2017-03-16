f = open("techno.small.in", "r")

T = int(f.readline())
N = []
W = []

R = []

for i in range(0, T):
    N.append( int(f.readline()) )
    l = []
    for j in range(0, N[i]):
        l.append( f.readline().strip() )
    W.append(l)

f.close()


for i in range(0, T):
    n = N[i]
    words = W[i]

    first = []
    second = []

    for w in words:
        first.append(w.split()[0])
        second.append(w.split()[1])

    numfake = 0

    for j in range(0, len(words)):
        w1 = first[j]
        w2 = second[j]

        c1 = first.count(w1)
        c2 = second.count(w2)

        if ( c1 > 1 and c2 > 1 ):
            numfake += 1

    print numfake
    R.append(numfake)

f = open("techno.out", "w")

for m in range(0, T):
    f.write("Case #" + str(m + 1) + ": " + str(R[m]) + "\n")
        
f.close()

print "done"

