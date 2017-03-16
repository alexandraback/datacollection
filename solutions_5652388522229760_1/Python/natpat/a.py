for i in range(int(raw_input())):
    case = i+1
    n = int(raw_input())
    found = [False] * 10
    
    if n == 0:
        print "Case #" + str(case) + ": INSOMNIA"
        continue

    complete = False
    mult = 1
    while not complete:
        num = mult * n
        strnum = str(num)
        for c in strnum:
            found[int(c)] = True
        
        complete = True
        for b in found:
            if not b:
                complete = False
                break

        if(complete):
            print "Case #" + str(case) + ": " +  str(num)
            break

        mult+=1

    if not complete:
        print "Case #" + str(case) + ": INSOMNIA"

            
    
