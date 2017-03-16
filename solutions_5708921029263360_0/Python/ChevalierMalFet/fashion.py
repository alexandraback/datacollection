# Started to do some by hand to look for the pattern, realized I could
# just do the whole small set by hand in a few minutes...


'''def generateFashions(jackets,pants,shirts,k):
    # First, write out the Js and Ps. As many copies as the minimum of S or K
    fashions = []
    for i in range(jackets):
        for j in range(pants):
            fashions += [str(i+1) + ' ' + str(j+1) + ' ' for x in range(min(shirts,k))]

    # Now, fill in the shirts. Some things to note:
    #   If k >= shirts, no need to do any fancy cycling.
    #   If k < shirts, need to cycle where we start 
    
'''


def stupidLookup(j,p,s,k):
    if j == 1:
        if p == 1:
            return ['11'+str(x) for x in range(1, min(s,k) + 1)]
        elif p == 2:
            if s == 2:
                if k == 1:
                    return ['111','122']
                else:
                    return ['111','112','121','122']
            elif s == 3:
                if k == 1:
                    return ['111','122']
                elif k == 2:
                    return ['111','112','121','122']
                else:
                    return ['111','112','113','121','122','123']
        elif p == 3:
            if k == 1:
                return ['111', '122', '133']
            elif k == 2:
                return ['111', '112', '123','121','132','133']
            else:
                return ['111','112','113','121','122','123','131','132','133']

    elif j == 2:
        if p == 2:
            if s == 2:
                if k == 1:
                    return ['111','122','212','221']
                else:
                    return ['111','112','121','122','211','212','221','222']
            elif s == 3:
                if k == 1:
                    return ['111','122','212','221']
                elif k == 2:
                    return ['111','112','121','122','211','212','221','222']
                else:
                    return ['111','112','113','121','122','123',
                            '211','212','213','221','222','223']
        elif p == 3:
            if k == 1:
                return ['111','122','133','212','223','231']
            elif k == 2:
                return ['111','112','123','121','132','133',
                        '212','213','221','222','233','231']
            else:
                return ['111','112','113','121','122','123',
                        '131','132','133','211','212','213',
                        '221','222','223','231','232','233']

    elif j == 3:
        if k == 1:
            return ['111','122','133','212','223','231','313','321','332']
        elif k == 2:
            return ['111','112','123','121','132','133',
                    '212','213','221','222','233','231',
                    '313','311','322','323','331','332']
        else:
            return ['111','112','113','121','122','123',
                    '131','132','133','211','212','213',
                    '221','222','223','231','232','233',
                    '311','312','313','321','322','323',
                    '331','332','333']

def getNiceString(j,p,s,k):
    l = stupidLookup(j,p,s,k)
    ret = str(len(l)) + '\n'
    for outfit in l:
        ret += outfit[0] + ' ' + outfit[1] + ' ' + outfit[2] + ' \n'
    return ret[:-1]

inputF = open('C-small-attempt0.in', 'r')
output = open('C-small-attempt0.out', 'w')

numCases = int(inputF.readline())

for i in range(numCases):
    line = [int(x) for x in inputF.readline().split()]
    j = line[0]
    p = line[1]
    s = line[2]
    k = line[3]
    output.write('Case #' + str(i+1) + ': ')
    output.write(getNiceString(j,p,s,k) + '\n')




inputF.close()
output.close()

                
