from string import maketrans
def main():
        filename = "input.in"
        inFile = open(filename,"r")
        outFile = open("outfile.txt","w")
        noOfCases = int(inFile.readline().rstrip())
        for i in range (0,noOfCases):
            line = inFile.readline().rstrip()
            lineTokens = line.split(' ')
            A = lineTokens[0]
            B = int(lineTokens[1])
            digits = len(A)
            noOfResults = 0
            new =""
            
            for no in range(int(A),B):
                ref_dict = dict()
                for h in range (1,digits):
                    temp = str(no)
                    new = temp[-h:]
                    new = new + temp[:-h]
                    
                    if int(new) > no and int(new) <= B:
                        if int(new) in ref_dict:
                            noOfResults -= 1
                        else:
                            ref_dict[int(new)] = no
                        noOfResults += 1
            OutputLine = "Case #{0:d}: ".format(i+1)
            OutputLine = OutputLine + str(noOfResults)
            OutputLine = OutputLine + "\n"
            outFile.write(OutputLine);
            
main()