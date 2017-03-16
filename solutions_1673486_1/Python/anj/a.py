
def solve (a, _b, probs):
    # Assume that the last letter is Enter
    b = _b+1

    eRestart = b+1
    best = eRestart
    
    fromStart=0
    pWin=1

    #print (eRestart)
    for p in probs:
        fromStart += 1
        
        pWin *= p
        numBackspaces = a - fromStart
        numRemaining = b - fromStart
        numWin = numBackspaces + numRemaining
        numLoose = numWin + b
        #print ("w" + str(numWin) + " l" + str(numLoose)) 
        
        pLoose = 1 - pWin
        e = pWin * numWin + pLoose * numLoose
        #print (e)

        if e < best:
            best = e

    return best

def go (fNameIn, fNameOut):
    inF = open (fNameIn, 'r')
    outF = open (fNameOut, 'w')
    T = int(inF.readline())
    print(T)
    for t in range(T):
        A, B = (int (i) for i in inF.readline().split())
        probs = (float (i) for i in inF.readline().split())
        
        out = "Case #" + str(t+1) + ": " + str(solve (A, B, probs)) + "\n"
        print (out)
        outF.write(out)
    inF.close()
    outF.close()

def g():
    go('in.txt', 'out.txt')
    
if __name__ == "__main__":
    # go ('in.txt', 'out.txt')
    pass

