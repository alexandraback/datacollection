# Recycled Numbers

def computeCyclicPermutaions(N):
    cyclic_permutations = {}
    for x in range(1, N + 1):
        try:
            if cyclic_permutations[x]:
                continue
        except:
            num = str(x)
            cycles = []
        
            for y in range(1, len(num) + 1):
                cycle = int(num[-y:] + num[:-y])
                if len(str(cycle)) == len(num) and cycle not in cycles:
                    cycles.append(cycle)

            cycles = sorted(cycles)
            for cycle in cycles:
                cyclic_permutations[cycle] = cycles
                
    return cyclic_permutations

i = open("C-large.in", "r")
o = open("C-large.out", "w")

T = int(i.readline())
cyclic_permutations = computeCyclicPermutaions(2000000)
print "Pre-computation complete"

for c in range(1, T + 1):
    A, B = map(int, i.readline().replace('\n','').split(' '))
    
    count = 0
    for x in range(A, B + 1):
        for y in cyclic_permutations[x]:
            if x < y <= B:
                count += 1

    o.write("Case #{0}: {1}\n".format(c, count))
    print "Case #{0}: {1}".format(c, count)

i.close()
o.close()