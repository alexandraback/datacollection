__author__ = 'Amir'


f_in = open("C:\Users\Amir\PycharmProjects\GoogleCodeJam\\files\\Pancakes\input1.txt")
f_out = open("C:\Users\Amir\PycharmProjects\GoogleCodeJam\\files\\Pancakes\output1.txt",'w')


line1 = map(int, (f_in.readline().split(" ")))
numOfCases = line1[0]
caseNum = 0

def pileFlip(pile, numOfPans):
    pileToFlip = pile[:(numOfPans)]
    pileToFlip = pileToFlip[::-1]
    pile_size = pileToFlip.__len__()

    for l in range(pile_size):
        if (pileToFlip[l] == '+'):
            if (pileToFlip.__len__() == 1):
                pileToFlip = '-'
            else:
                if (l == 0):
                    pileToFlip = '-' + pileToFlip[(l+1):]
                if (l == pileToFlip.__len__()):
                    pileToFlip = pileToFlip[:l] + '-'
                if ((l != 0) & (l != pileToFlip.__len__())):
                    pileToFlip = pileToFlip[:l] + '-' + pileToFlip[l+1:]
        else:
            if (pileToFlip.__len__() == 1):
                pileToFlip = '+'
            else:
                if (l == 0):
                    pileToFlip = '+' + pileToFlip[(l+1):]
                if (l == pileToFlip.__len__()):
                    pileToFlip = pileToFlip[:l] + '+'
                if ((l != 0) & (l != pileToFlip.__len__())):
                    pileToFlip = pileToFlip[:l] + '+' + pileToFlip[l+1:]
    pile = pileToFlip + pile[numOfPans:]


    return pile

def reducePile(pile, numOfFlips):
    pile_size = pile. __len__()
    if ((pile_size) == 0):
            print 'Case #'  + str(caseNum) + ': '  + str(numOfFlips)
            f_out.writelines('Case #'  + str(caseNum) + ': '  + str(numOfFlips) + '\n')
            return


    if (pile[pile_size-1] == '+'):
        while (pile_size > 0):
            if (pile[pile_size - 1] == '+'):
                pile = pile[:(pile_size-1)]
                pile_size -= 1
            else:
                break
        reducePile(pile, numOfFlips)
        return

    if (pile_size == 0 ):
        return numOfFlips
    # now, the pile has only '-' at the back:

    if (pile[0] == '-'):
        pile = pileFlip(pile, pile.__len__())
        reducePile(pile, numOfFlips+1)
        return

    else:
        flipNum = 0
        for l in range(pile_size):
            if (pile[l] == '+'):
                flipNum +=1
            else:
                break

        pile = pileFlip(pile, flipNum)
        reducePile(pile, numOfFlips+1)
        return


for n in range (numOfCases):
    caseNum += 1
    line = map(str, (f_in.readline().split(" ")))
    pile = line[0]
    if pile[pile.__len__() -1] == '\n':
        pile = pile[:(pile.__len__()-1)]

    numOfFlips = 0

    reducePile(pile, numOfFlips)



