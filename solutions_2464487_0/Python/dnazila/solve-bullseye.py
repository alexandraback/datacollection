import sys
#I used r and t variables with the wrong name

fname = sys.argv[1]

f = open(fname, "rt")

T = int(f.readline())

def ink_used(t, n):
    return (2 * n * t - 3 * n + 4 * n * (n+1) / 2)

def bin_search(low, high, r, t):
    #[low, high)
    if high - low < 2:
        return low
    mid = (low + high) / 2
    midf = ink_used(t, mid)
    if midf > r:
        return bin_search(low, mid, r, t)
    else:
        return bin_search(mid, high, r, t)

def handle_case(f, caseno):
    line = f.readline()
    fields = line.split()
    t = int(fields[0])
    r = int(fields[1])

    i = 1
    while ink_used(t, i) < r:
        i *= 2

    if ink_used(t, i) == r:
        print "Case #%d: %d" % (caseno, i)

    else:
        print "Case #%d: %d" %(caseno, bin_search(i / 2, i, r, t))

    



    
    

        

for case in range(T):
    handle_case(f, case+1)
        

    
