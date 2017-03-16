import fractions

good_denoms = []
for i in range(40):
    good_denoms.append(2**i)

input = open("input.txt", "r")

cases = int(input.readline())

for case in range(cases):
    part_elf = input.readline().split('/')
    fraction = float(part_elf[0]) / float(part_elf[1])
    greatest = fractions.gcd(int(part_elf[0]), int(part_elf[1]))
    if greatest > 1:
        denom = int(part_elf[1])/greatest
    else:
        denom = int(part_elf[1])
    count = 0
    result = -1
    parent = fraction
    for i in range(40):
        parent *= 2
        if fraction == 1.0:
            result = 0
            break
        elif parent >= 1.0:
            count += 1
            result = count
            break
        else:
            count += 1

    if denom not in good_denoms:
        result = "impossible"
    elif result == -1:
        result = "impossible"
    else:
        result = str(result)

    print "Case #%i: %s" % (case+1, result)

input.close()




