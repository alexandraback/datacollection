infile = open("A-large.in", "rU")
outfile = open("Output.txt", "w")

linenum = 0
case = 0
for line in infile:
    if linenum != 0:
        line = line.strip()
        if linenum % 2 == 1:
            listy = line.split(" ")
            A = int(listy[0])
            B = int(listy[1])
        else:
            case += 1
            probs = line.split(" ")
            backspace = [0]*(A+1)
            enter = B+2
            for i in xrange(0, len(probs)):
                probs[i] = float(probs[i])

            ##Probabilty for keep typing

            product = 1
            for p in probs:
                product *= p
            for backnum in xrange(0, A+1):
                if backnum != 0:
                    product /= probs[A-backnum]
                #print backnum, index, product, probs
                backspace[backnum] = product*(B-A+1+backnum*2) + (1-product)*((B+1)+(B-A+1+backnum*2))
            #print backspace, enter
            #print float(min(min(backspace), enter))
            outfile.write("Case #" + str(case) + ": " + str(float(min(min(backspace), enter))) + "\n")                 
    linenum += 1
    
outfile.close();
