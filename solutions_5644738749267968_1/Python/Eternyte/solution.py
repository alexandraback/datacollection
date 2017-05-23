import copy

def main():
    fileName = "D-large.in"
    file = open(fileName)

    # Loop for the number of tests there are.
    for case in range(1, int(file.readline()) + 1):
        # Read in the values.
        numBlocks = int(file.readline())
        naoBlocks = [float(block) for block in file.readline().split()]
        kenBlocks = [float(block) for block in file.readline().split()]

        # Sort the blocks.
        naoBlocks.sort()
        kenBlocks.sort()

        # Naomi is a dirty cheat.
        tempNaoBlocks = copy.deepcopy(naoBlocks)
        tempKenBlocks = copy.deepcopy(kenBlocks)
        fakePoints = 0
        
        kBlockIndex = 0
        while(kBlockIndex < len(tempKenBlocks)):
            for nBlockIndex in range(len(tempNaoBlocks)):
                nBlock = tempNaoBlocks[nBlockIndex]
                kBlock = tempKenBlocks[kBlockIndex]
                if nBlock > kBlock and nBlock != -1:
                    tempNaoBlocks[nBlockIndex] = -1
                    fakePoints += 1
                    break;
            else:
                for nBlockIndex in range(len(tempNaoBlocks)):
                    if (tempNaoBlocks[nBlockIndex] != -1):
                        tempNaoBlocks[nBlockIndex] = -1
                        break;
            kBlockIndex += 1

        # Naomi plays fairly.
        tempNaoBlocks = copy.deepcopy(naoBlocks)
        tempKenBlocks = copy.deepcopy(kenBlocks)
        truePoints = 0

        for nBlockIndex in range(len(tempNaoBlocks)):
            for kBlockIndex in range(len(tempKenBlocks)):
                nBlock = tempNaoBlocks[nBlockIndex]
                kBlock = tempKenBlocks[kBlockIndex]
                if kBlock > nBlock and nBlock != -1 and kBlock != -1:
                    tempNaoBlocks[nBlockIndex] = -1
                    tempKenBlocks[kBlockIndex] = -1
                    break
            else:
                for kBlockIndex in range(len(tempKenBlocks)):
                    if (tempKenBlocks[kBlockIndex] != -1):
                        tempNaoBlocks[nBlockIndex] = -1
                        tempKenBlocks[kBlockIndex] = -1
                        truePoints += 1
                        break;

        # Print out the results.
        print("Case #" + str(case) + ": " \
              + str(fakePoints) + " " + str(truePoints))

                    
if __name__ == "__main__":
    main()
