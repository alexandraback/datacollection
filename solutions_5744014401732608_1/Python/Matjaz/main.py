T = int(raw_input())

for case in range(1,T+1):
    B,M = [int(x) for x in raw_input().split(" ")]
    if 2**(B-2)< M :
        print "Case #"+str(case)+": IMPOSSIBLE"
        continue
    print "Case #"+str(case)+": POSSIBLE"
    rows = ["" for i in range(B)]
    for i in range(1,B):
        for j in range(B):
            if i >= j :
                rows[i] += "0"
            else:
                rows[i] += "1"

    if (M == 2**(B-2)):
        rows[0] = "0" + (B-1)*"1"
    else:
        rows[0] = "0"
        for i in reversed(range(1,B-1)):
            if M % 2 == 1:
                rows[0] = "1" + rows[0]
            else:
                rows[0] = "0" + rows[0]
            M = M / 2

        rows[0] = "0" + rows[0]


    for i in range(B):
        print rows[i]