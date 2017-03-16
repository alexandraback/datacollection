def work():
    a, b = input().strip().split()

    bigger = 0
    
    rA = ""
    rB = ""


    for cA, cB in zip(a, b):
        if bigger == 0 and cA == "?" and cB == "?":
            rA += "0"
            rB += "0"
            continue

        if bigger == 0 and cA == "?":
            rA += cB
            rB += cB
            continue

        if bigger == 0 and cB == "?":
            rA += cA
            rB += cA
            continue

        if bigger == 0:
            if cA < cB: 
                bigger = 1 
            elif cA > cB: 
                bigger = -1 
            
            rA += cA
            rB += cB

            continue

        if cA == "?":
            if bigger == 1:
                rA += "9"
            else:
                rA += "0"

        if cB == "?":
            if bigger == 1:
                rB += "0"
            else:
                rB += "9"

        if cA != "?": rA += cA
        if cB != "?": rB += cB


    return rA + " " + rB




T = int(input())
for test_case in range(T):
    print ("Case #{}:".format(test_case+1), work())