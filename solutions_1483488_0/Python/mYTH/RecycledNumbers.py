# Recycled Numbers

i = open("C-small-attempt0.in", "r")
o = open("C-small.out", "w")

T = int(i.readline())

for c in range(1, T + 1):
    A, B = map(int, i.readline().replace('\n','').split(' '))
    
    result = []
    for x in range(A, B + 1):
        num = str(x)
        cycles = []
        
        for y in range(1, len(num) + 1):
            cycle = int(num[-y:] + num[:-y])
            if cycle >= A and cycle <= B and cycle not in cycles:
                cycles.append(cycle)

        cycles = sorted(cycles)
        for p in range(len(cycles) - 1):
            for q in range(p + 1, len(cycles)):
                if (cycles[p], cycles[q]) not in result:
                    result.append((cycles[p], cycles[q]))

    o.write("Case #{0}: {1}\n".format(c, len(result)))

i.close()
o.close()