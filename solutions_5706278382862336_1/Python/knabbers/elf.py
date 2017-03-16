def solve(file):
    import math
    from fractions import gcd
    infile = open(file,'r')
    lines = infile.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    linenumber = 1 # line number
    casen = 1 # case number
    while nCases > 0:
        print("case: " + str(casen))
        line = lines[linenumber].replace('\n', "").split("/")
        
        P = int(line[0])
        Q = int(line[1])
        #print (P)
        #print(Q)

        result = ""

        # simplify
        
##        while P&1 == 0:
##            P >>= 1
##            if Q&1:
##                result = "impossible"
##                break
##            Q >>= 1
##
##

        g = gcd(P,Q)
        P = int(P/g)
        Q = int(Q/g)
        #print(P)
        #print(Q)


        if Q>pow(2,40) or Q<P:
            result = "impossible"


        if not is_power2(Q):
            result = "impossible"

        if result != "impossible":
            i = 41
            while P&(1<<i) ==0:
                i -= 1
            j = 41
            while Q&(1<<j) ==0:
                j -= 1
            result = str(j-i)
            

            
                
        outf.write("Case #" + str(casen) +": " + result + "\n")

        linenumber += 1
        nCases -= 1
        casen+=1

    infile.close()
    outf.close()



def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)
