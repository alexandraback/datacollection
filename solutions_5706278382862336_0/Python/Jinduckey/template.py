fh = open("A-small-attempt1 (3).in", "r")
fh2 = open("output.txt", "w")
testCases = fh.readline()

for testCase in xrange(int(testCases)):
    P, Q = [int(s) for s in fh.readline().split("/")]

    possible = True
    if 2**40 % Q != 0:
        possible = False
    for i in range(1, 41):
        if Q % 2 == 0:
            Q /= 2
            if P >= Q:
                ans = i
                break
        else:
            possible = False
            break

    if not possible:
        ans = "impossible"

    #print ans
    # ans =

    fh2.write("Case #" + str(testCase + 1) + ": " + str(ans) + "\n")
    

fh.close()
fh2.close()
    
    
    
        
