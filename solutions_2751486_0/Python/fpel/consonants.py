import os
import sys

VOWELS = set(['a', 'e', 'i', 'o', 'u'])

def v(ss):
    for a in ss:
        if a in VOWELS:
            return False
    return True

def run(inputFilePath):
    with open(inputFilePath, 'r') as inputFile:
        with open(inputFilePath+'-output.txt', 'w') as outputFile:
            T = int(inputFile.readline())
            print("The input file contains", T, "test cases")
            for t in range (1, T+1):
                print("Processing case #" + str(t))
                input = inputFile.readline().split()
                name = input[0]
                n = int(input[1])
                #print("Name:", name, "n:", str(n))
                nameLength = len(name)
                lastPos = 0
                result = 0
                for i in range(0, nameLength+1-n):
                    ss = name[i:i+n]
                    if v(ss) is True:
                        left = i - lastPos
                        right = nameLength - i - n
                        lastPos = i+1
                        result += (1+left)*(right+1)
                        #print ('ss:', ss, 'left:', left, 'right', right)
                #print("y:", result)
                output = "Case #" + str(t) + ": " + str(result) + "\n"
                print(output)
                outputFile.write(output)
                    

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print ("Usage: ", sys.argv[0], "input-file")
        exit(0)
    inputFilePath = sys.argv[1]
    print("Working on input file: [", inputFilePath, "].")
    if not os.path.isfile(inputFilePath):
        print ("Error: the input file is not a valid file")
        exit(1)
    run(inputFilePath)
    print('End.')