T = int(input())
for i in range(1, T+1):
    line = input()
    prechody = 0
    for j in range(1, len(line)):
        if (line[j-1] != line[j]):
            prechody += 1
    if ((line[len(line)-1]) == '-'):
        prechody += 1


    print("Case #"+str(i) + ": " + str(prechody))
