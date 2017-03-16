__author__ = 'Ashutosh'

import sys

xray = {
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

def xx(tu, l):
    mark, sym = xray[tu[1]][l]
    return tu[0] * mark, sym

if __name__ == '__main__':
    for tc in range(int(sys.stdin.readline())):
        counter, repeat = map(int, sys.stdin.readline().split())
        iterate = sys.stdin.readline()
        cur = (1, '1')
        pointer = 0
        while pointer < 4 * counter:
            cur = xx(cur, iterate[pointer % counter])
            pointer += 1
            if cur[0] == 1 and cur[1] == 'i':
                break
        if 4 * counter == pointer:
            print('Case #%d: NO' % (tc + 1))
        else:
            cur = (1, '1')
            while pointer < 8 * counter:
                cur = xx(cur, iterate[pointer % counter])
                pointer += 1
                if cur[0] == 1 and cur[1] == 'j':
                    break
            if 8 * counter == pointer:
                print('Case #%d: NO' % (tc + 1))
            else:
                cur = (1, '1')
                while pointer < 12 * counter:
                    cur = xx(cur, iterate[pointer % counter])
                    pointer += 1
                    if cur[0] == 1 and cur[1] == 'k':
                        break
                if 12 * counter == pointer:
                    print('Case #%d: NO' % (tc + 1))
                elif repeat <= (pointer - 1) // counter:
                    print('Case #%d: NO' % (tc + 1))
                else:
                    cur = (1, '1')
                    left = (repeat - 1 - (pointer - 1) // counter) % 4
                    while pointer % counter != 0:
                        cur = xx(cur, iterate[pointer % counter])
                        pointer += 1
                    for i in range(left * counter):
                        cur = xx(cur, iterate[pointer % counter])
                        pointer += 1
                    if cur[0] == 1 and cur[1] == '1':
                        print('Case #%d: YES' % (tc + 1))
                    else:
                        print('Case #%d: NO' % (tc + 1))