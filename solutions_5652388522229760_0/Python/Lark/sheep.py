f = open("sheep.small.in", "r")

T = int(f.readline())

N = []

for i in range(0, T):
    N.append(int(f.readline()))

f.close()

print "num tests: " + str(T)

print "start"

C = [0 for j in range(T)]
K = [0 for j in range(T)]

def fill(r, n):
    k = n
    while ( k > 0 ):
        d = k % 10
        k = k / 10
        r[d] = 1

def check(r):
    return sum(r) == 10

for i in range(0, T):
    n = N[i]
    r = [0 for j in range(10)]

    print "test: " + str(n)

    if ( n > 0 ):
        k = 1
        while (not check(r)):
            fill(r, n*k)
            k += 1
        K[i] = (k-1)
        C[i] = n * (k-1)

print "stop"

f = open("sheep.out", "w")

for i in range(0, T):
    if ( C[i] > 0 ):
        f.write("Case #" + str(i + 1) + ": " + str(C[i]) + "\n")
    else:
        f.write("Case #" + str(i + 1) + ": " + str("INSOMNIA") + "\n")

        
f.close()

print "done"
