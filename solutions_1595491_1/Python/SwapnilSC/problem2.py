def main():
        filename = "input.in"
        inFile = open(filename,"r")
        outFile = open("outfile.txt","w")
        noOfCases = int(inFile.readline().rstrip())
        for i in range (0,noOfCases):
                    line = inFile.readline().rstrip()
                    lineTokens = line.split(' ')
                    noOfGoogs = int(lineTokens[0])
                    noOfSuprises = int(lineTokens[1])
                    threshold = int(lineTokens[2])
                    noOfBests = 0
                    diff = 0
                    for j in range (0,noOfGoogs):
                        if int(lineTokens[j+3]) <> 0:
                            avgScore = int(lineTokens[j+3])/3
                            diff = 0
                            if avgScore >= threshold:
                                noOfBests += 1
                            else:
                                if avgScore == 0:
                                    diff = int(lineTokens[j+3]) - (avgScore)
                                if avgScore*3 <> int(lineTokens[j+3]):
                                    diff = int(lineTokens[j+3]) - (avgScore * 3)
                                    if avgScore + 1 >= threshold:
                                        noOfBests += 1
                                    else:
                                        if diff == 2 and avgScore + 2 >= threshold and noOfSuprises <> 0:
                                            noOfBests += 1
                                            noOfSuprises -= 1
                                else:
                                    if avgScore == 0:
                                        if avgScore + diff >= threshold:
                                            if diff == 1:
                                                noOfBests += 1
                                            else:
                                                if noOfSuprises <> 0:
                                                    noOfSuprises -= 1
                                                    noOfBests += 1
                                    else:
                                        if avgScore + 1 >= threshold and noOfSuprises <> 0:
                                            noOfBests += 1
                                            noOfSuprises -= 1
                        else:
                            if threshold == 0:
                                noOfBests += 1
                                
                    OutputLine = "Case #{0:d}: ".format(i+1)
                    OutputLine = OutputLine + str(noOfBests) + "\n"
                    outFile.write(OutputLine)
main()
                                
                                    
                            
            