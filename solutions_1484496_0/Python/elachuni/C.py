f = open('C-small-attempt0.in')

def find_sums(sums, n):
    for s in sums.keys():
        newsum = sums[s] + [n]
        if s + n in sums:
            return newsum, sums[s + n]
        sums[s + n] = newsum
    if n in sums:
        return sums[n], [n]
    sums[n] = [n]

T = int(f.readline().strip())
for case in range(T):
    print "Case #%d:" % (case + 1)
    Ns = [int(x) for x in f.readline().strip().split()][1:]
    sums = {}
    for n in Ns:
        result = find_sums(sums, n)
        if result:
            common = [a for a in result[0] if a in result[1]]
            A = [a for a in result[0] if not a in common]
            B = [a for a in result[1] if not a in common]
            print ' '.join(str(x) for x in A)
            print ' '.join(str(x) for x in B)
            break
    else:
        print "Impossible"
