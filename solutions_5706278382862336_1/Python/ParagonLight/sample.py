import utils



def findRoot(string):
    chars = list(string)
    newChars = []
    identicalFlag = False
    lastChar = "-1"
    for index in range(len(chars)):
        char = chars[index]
        if char == lastChar:
            identicalFlag == True
            continue
        else:
            identicalFlag = False
            newChars.append(lastChar)            
            lastChar = char
    newString = ''.join(newChars)
    print newString
    return newString

def isPowerOf2(num):
    return ((num & (num - 1)) == 0) and num != 0


def solve(pqFloat):
    if pqFloat>= 0.5:
        oneOfParents = 1
        return 1
    else:
        oneOfParents = 2 * pqFloat
        return oneOfParents

def gcd(a,b):
         while 1:          # loop until break
            r = a%b        # step 1
	    if r == 0:     # step 2
	        break      # we're done
	    else:
	        a,b = b,r  # step 3
	 return b

if __name__ == "__main__":
    inputFile = "A-large.in"
    #inputFile = "A-small-attempt1.in"
    #inputFile = "input"
    outputFile = "outputQ1"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()

    base = {2:1, 4:1, 8:1, 16:1, 32:1, 64:1, 128:1, 256:1, 512:1, 1024:1}
    cases = cases.replace("\n","")
    print cases
    for index in range(1, int(cases) + 1):
        pq = inputData.next()        
        pqs = pq.split("/")
        a = int(pqs[0])
        b = int(pqs[1])
        gcdN = gcd(a,b)
        print gcdN
        a = int(pqs[0]) / gcdN
        b = int(pqs[1]) / gcdN
        if not isPowerOf2(b):
            result = "impossible"
        else:
            pqFloat = float(a)/float(b)

            print pqFloat, pq
            generation = 0
            while pqFloat < 1:
                pqFloat = solve(pqFloat)
                print generation, pqFloat
                generation += 1
        
            if generation > 40:
                result = "impossible"
            else:
                result = generation            

        outputString = "Case #" + str(index)+ ": " + str(result)
        print outputString
        outputData.write(outputString+"\n")
                
            



