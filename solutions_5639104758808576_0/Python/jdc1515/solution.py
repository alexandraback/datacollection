with open("A-small-attempt0.in") as f:
    lines = f.readlines()

outputname = 'outputAfinal.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

for i in range(cases):
    splitrow = lines[linenum].split(" ")
    count = int(splitrow[0])
    peoplecount = splitrow[1]

    total = 0
    extras = 0
    for j in range(count+1):
        if j > total:
            extras += j - total
            total = j
        total += int(peoplecount[j])

    f.write("Case #" + str(i+1) + ": " + str(extras) + "\n")
    linenum += 1

f.close()

with open(outputname, 'r') as f:
    print(f.read())
