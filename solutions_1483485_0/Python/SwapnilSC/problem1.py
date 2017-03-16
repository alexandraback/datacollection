from string import maketrans
def main():
        filename = "input.in"
        inFile = open(filename,"r")
        outFile = open("outfile.txt","w")
        original = "abcdefghijklmnopqrstuvwxyz"
        googler =  "ynficwlbkuomxsevzpdrjgthaq"
        transtab = maketrans(googler, original)
        noOfCases = int(inFile.readline().rstrip())
        for i in range (0,noOfCases):
            line = inFile.readline().rstrip()
            line = line.translate(transtab)
            OutputLine = "Case #{0:d}: ".format(i+1)
            OutputLine = OutputLine + line
            OutputLine = OutputLine + "\n"
            outFile.write(OutputLine);
            
main()