import sys
import math

f = open('C-small-attempt1.in','r')

djMap = {
    '1': {
        '1': (1, '1'),
        'i': (1, 'i'),
        'j': (1, 'j'),
        'k': (1, 'k')
    },
    'i': {
        '1': (1, 'i'),
        'i': (-1, '1'),
        'j': (1, 'k'),
        'k': (-1, 'j')
    },
    'j': {
        '1': (1, 'j'),
        'i': (-1, 'k'),
        'j': (-1, '1'),
        'k': (1, 'i')
    },
    'k': {
        '1': (1, 'k'),
        'i': (1, 'j'),
        'j': (-1, 'i'),
        'k': (-1, '1')
    }
}

def multiplicationIndex(dbArray, xx):
    signature, symantic = djMap[dbArray[1]][xx]
    return dbArray[0] * signature, symantic

def solve():
    for caseN in range(int(f.readline())):
        cc, again = map(int, f.readline().split())
        opop = f.readline()
        current = (1, '1')
        cursor = 0
        while cursor < 4 * cc:
            current = multiplicationIndex(current, opop[cursor % cc])
            cursor += 1
            if current[0] == 1 and current[1] == 'i':
                break
        if 4 * cc == cursor:
            print('Case #%d: NO' % (caseN + 1))
        else:
            current = (1, '1')
            while cursor < 8 * cc:
                current = multiplicationIndex(current, opop[cursor % cc])
                cursor += 1
                if current[0] == 1 and current[1] == 'j':
                    break
            if 8 * cc == cursor:
                print('Case #%d: NO' % (caseN + 1))
            else:
                current = (1, '1')
                while cursor < 12 * cc:
                    current = multiplicationIndex(current, opop[cursor % cc])
                    cursor += 1
                    if current[0] == 1 and current[1] == 'k':
                        break
                if 12 * cc == cursor:
                    print('Case #%d: NO' % (caseN + 1))
                elif again <= (cursor - 1) // cc:
                    print('Case #%d: NO' % (caseN + 1))
                else:
                    current = (1, '1')
                    left = (again - 1 - (cursor - 1) // cc) % 4
                    while cursor % cc != 0:
                        current = multiplicationIndex(current, opop[cursor % cc])
                        cursor += 1
                    for i in range(left * cc):
                        current = multiplicationIndex(current, opop[cursor % cc])
                        cursor += 1
                    if current[0] == 1 and current[1] == '1':
                        print('Case #%d: YES' % (caseN + 1))
                    else:
                        print('Case #%d: NO' % (caseN + 1))
