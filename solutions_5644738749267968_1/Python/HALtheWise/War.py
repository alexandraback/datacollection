#file('C-large-practice.in').read()
#

almost1 = 1.0 - 1e-8
almost0 = 1e-8

def kMove(kblocks, told): #returns chosen block
    assert told not in kblocks
    assert len(set(kblocks)) == len(kblocks)
    if told > max(kblocks):
        return min(kblocks)
    else:
        return min([x for x in kblocks if x > told])

def nMove(nblocks): #returns told
    assert len(set(nblocks)) == len(nblocks)
    return max(nblocks)

def nCheatMove(nblocks, kblocks): #returns (chosen, told)
    nblocks.sort()
    kblocks.sort()
    num = len(nblocks)
    if not [0 for i in range(num) if nblocks[i] <= kblocks[i]]: #You will win all future turns
        return nblocks[0], almost1
    else: #make him pay for a win
        return min(nblocks), max(kblocks)-almost0
    
def processAllInput(text, toFile = False):
    fileName = text
    if toFile:
        text = file(fileName).read()
    finalResult = []
    numTests = int(text.split('\n')[0])
    lines = text.split('\n')
    for i in range(numTests):
        #Problem-specific code starts here############
        
        message = lines[3*i+1:3*i+4]
        numTurns = int(message[0])
        nblocks = map(float, message[1].split())
        kblocks = map(float, message[2].split())
        assert len(nblocks) == numTurns and len(kblocks) == numTurns

        nocheatscore = 0 ##START NOCHEAT ROUND
        nblocksnew = nblocks[:]
        kblocksnew = kblocks[:]
        for turn in range(numTurns):
            told = nMove(nblocksnew)
            response = kMove(kblocksnew, told)
            if told > response:
                nocheatscore += 1
            nblocksnew.remove(told)
            kblocksnew.remove(response)

        
        cheaterscore = 0##START CHEATING
        nblocksnew = nblocks[:]
        kblocksnew = kblocks[:]
        for turn in range(numTurns):
            chosen, told = nCheatMove(nblocksnew, kblocksnew)
            response = kMove(kblocksnew, told)
            if chosen > response:
                cheaterscore += 1
            assert (chosen > response) == (told > response)
            nblocksnew.remove(chosen)
            kblocksnew.remove(response)
            

            
        line = 'Case #{0}: {1} {2}'.format(i+1, cheaterscore, nocheatscore)
        
        #Problem-specific code ends here##############
        if not toFile:
            print line
        finalResult.append(line)
    if toFile:
        file(fileName.split('.')[0]+'.out', 'w').write('\n'.join(finalResult))
