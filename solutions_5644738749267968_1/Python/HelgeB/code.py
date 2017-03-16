'''

@author: Helge
'''

def kensStrategy(choosen, kensBlocks):
    index = 0
    for b in kensBlocks:
        if b>choosen:
            return index
        index = index + 1
    return 0


def pointForNaomi(choosenNaomi, choosenKen):
    if choosenKen > choosenNaomi:
        return 0
    else:
        return 1
    
def naomisPointsWar(N, naomisBlocks, kensBlocks):
    naomisPoints = 0
    for gameRound in range(0, N):
        choosen = naomisBlocks.pop()
        naomisPoints = naomisPoints + pointForNaomi(choosen, kensBlocks.pop(kensStrategy(choosen, kensBlocks)))
    return naomisPoints

def naomisPointsDeceitfulWar(N, naomisBlocks, kensBlocks):
    naomisPoints = 0
    for gameRound in range(0, N):
        #Naomi's strategy
        choosen = naomisBlocks.pop(0)
        if len(kensBlocks) > 1:
                        
            kensBiggest = kensBlocks[len(kensBlocks)-1]
            kensSecondBiggest = kensBlocks[len(kensBlocks)-2]
            
            if choosen > kensBlocks[0]:
                told = (kensBiggest + 1) / 2
            else:
                told = (kensBiggest + kensSecondBiggest) / 2
        else:
            told = choosen
        
        naomisPoints = naomisPoints + pointForNaomi(choosen, kensBlocks.pop(kensStrategy(told, kensBlocks)))
    return naomisPoints

file = open('D-large.in', 'r')
output = open('output', 'w')

T = file.readline()

for x in range(0, int(T)):
    N = int(file.readline().replace('\n', ''))
    naomisBlocks = list(map(lambda l: float(l), file.readline().replace('\n', '').split(' '))) 
    naomisBlocks.sort()
    kensBlocks = list(map(lambda l: float(l), file.readline().replace('\n', '').split(' ')))
    kensBlocks.sort()
    y = naomisPointsDeceitfulWar(N, naomisBlocks.copy(), kensBlocks.copy())
    z = naomisPointsWar(N, naomisBlocks, kensBlocks)
    solution = 'Case #' + str(x+1) + ': ' + str(y) + ' ' + str(z) + '\n'
    output.write(solution)
    #print(solution)