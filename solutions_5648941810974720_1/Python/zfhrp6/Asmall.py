from read import read
from Euler import primecheck

i2a = {
    0:'ZERO',
    1:'ONE',
    2:'TWO',
    3:'THREE',
    4:'FOUR',
    5:'FIVE',
    6:'SIX',
    7:'SEVEN',
    8:'EIGHT',
    9:'NINE'
}

def detect(st):
    if 'Z' in st:
        return 0
    elif 'X' in st:
        return 6
    elif 'G' in st:
        return 8


def detect_fromdic(stdic):
    ret = []
    if 'Z' in stdic:
        tmp = stdic['Z']
        stdic['Z'] -= tmp
        stdic['E'] -= tmp
        stdic['R'] -= tmp
        stdic['O'] -= tmp
        for _ in range(tmp):
            ret.append(0)
    if 'X' in stdic:
        tmp = stdic['X']
        stdic['X'] -= tmp
        stdic['S'] -= tmp
        stdic['I'] -= tmp
        for _ in range(tmp):
            ret.append(6)
    if 'G' in stdig:
        tmp = stdic['G']
        stdic['E'] -= tmp
        stdic['I'] -= tmp
        stdic['G'] -= tmp
        stdic['H'] -= tmp
        stdic['T'] -= tmp
    return stdic,ret


def valid(stdic):
    # negative logic
    ret = True
    for i in range(10):
        tmp = True
        for c in i2a(i):
            if c in stdic:
                tmp *= stdic[c] == 0
            else:
                tmp *= not c in stdic
        ret *= tmp

    # positive logic
    return not ret


def sub_s(stdic, num):
    for c in i2a[num]:
        stdic[c] -= 1
    return stdic


def num_in_s(stdic, num):
    ret = True
    if num == 3:
        for c in 'THREE':
            ret *= c in stdic and stdic[c] > 0 and stdic['E'] > 1
    elif num == 7:
        for c in 'SEVEN':
            ret *= c in stdic and stdic[c] > 0 and stdic['E'] > 1
    elif num == 9:
        for c in 'NINE':
            ret *= c in stdic and stdic[c] > 0 and stdic['N'] > 1
    else:
        for c in i2a[num]:
            ret *= c in stdic and stdic[c] > 0
    return ret


def s2dic(st):
    ret = {}
    for c in st:
        if c in ret:
            ret[c] += 1
        else:
            ret[c] = 1
    return ret

def allzerocheck(stdic):
    ret = True
    for k in stdic.keys():
        ret *= stdic[k]==0
    return ret


def calc(st):
    ret = ''
    stdic = s2dic(st)
    while 'Z' in stdic and stdic['Z']>0:
        ret += str(0)
        sub_s(stdic, 0)
    while 'X' in stdic and stdic['X']>0:
        ret += str(6)
        sub_s(stdic, 6)
    while 'G' in stdic and stdic['G']>0:
        ret += str(8)
        sub_s(stdic, 8)
    while 'S' in stdic and stdic['S']>0:
        ret += str(7)
        sub_s(stdic, 7)
    while 'V' in stdic and stdic['V']>0:
        ret += str(5)
        sub_s(stdic, 5)
    while 'F' in stdic and stdic['F']>0:
        ret += str(4)
        sub_s(stdic, 4)
    while 'W' in stdic and stdic['W']>0:
        ret += str(2)
        sub_s(stdic, 2)
    while 'I' in stdic and stdic['I']>0:
        ret += str(9)
        sub_s(stdic, 9)
    while 'O' in stdic and stdic['O']>0:
        ret += str(1)
        sub_s(stdic, 1)
    while 'T' in stdic and stdic['T']>0:
        ret += str(3)
        sub_s(stdic, 3)
    return ''.join(sorted(ret))

    # while not allzerocheck(stdic):
    #     for i in range(10):
    #
    # for c in st:
    #     if ret == '':
    #         ret += c
    #     elif c >= ret[0]:
    #         ret = c + ret
    #     else:
    #         ret = ret + c
    # return ret


def main():
    import sys
    infile = read(sys.argv[1])
    outfilename = sys.argv[2]
    def it():
        return next(infile)

    T = int(it())

    with open(outfilename, 'w') as outfile:
        for caseidx in range(1, T+1):
            S = sorted(it())
            ans = calc(S)
            outfile.write('Case #{}: {}\n'.format(caseidx, ans))
            print('Case #{}: {}'.format(caseidx, ans))


if __name__ == '__main__':
    main()
