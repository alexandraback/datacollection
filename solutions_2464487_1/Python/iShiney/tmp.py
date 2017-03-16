fin = open("A-large.in", "r")
fout = open("A-large.out", "w")

cases = int(fin.readline())

def f(n, r):
    return n * (2 * r + 2 * n - 1)

for casen in xrange(1, cases+1):
    r, t = map(int, fin.readline().split())
    #print r, t
    low = 0
    high = 10000000000000000000000000
    while(low < high):
        mid = low + (high-low)/2
        if f(mid, r) > t: #is good
            high = mid
        else:
            low = mid+1
    #print low-1
    fout.write("Case #" + str(casen) + ": " + str(low-1) + "\n")

fin.close()
fout.close()
