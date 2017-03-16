from read import read
from Euler import primecheck


def make1(s):
    ret = []
    for i in range(10):
        tmps = s.replace('?', str(i))
        ret.append(tmps)
    return ret

def make2(s):
    ret = []
    for i in range(10):
        tmps = s[:s.index('?')]+str(i)+s[s.index('?')+1:]
        for j in range(10):
            ret.append(tmps.replace('?', str(j)))
    return ret

def make3(s):
    ret = []
    for i in range(10):
        tmps = s[:s.index('?')] + str(i) + s[s.index('?')+1:]
        for j in range(10):
            tmpss = tmps[:tmps.index('?')] + str(j) + tmps[tmps.index('?')+1:]
            for k in range(10):
                ret.append(tmpss.replace('?', str(k)))
    return ret


def make(s, num):
    if num==1:
        return make1(s)
    if num==2:
        return make2(s)
    if num==3:
        return make3(s)
    if num==0:
        return [s]
    else:
        raise Exception


def calc(st):
    ret = ''
    coder, jammer = st.split()
    pcoder = make(coder, coder.count('?'))
    pjammer = make(jammer, jammer.count('?'))
    print(st,pcoder,pjammer)
    mdiff = [99999, ('99999','99999')]
    for cscore in pcoder:
        for jscore in pjammer:
            di = abs(int(cscore)-int(jscore))
            if di == mdiff[0]:
                if (cscore == mdiff[1][0] and jscore < mdiff[1][1]) or cscore < mdiff[1][0]:
                    mdiff[0] = di
                    mdiff[1] = (cscore, jscore)
            elif di < mdiff[0]:
                mdiff[0] = di
                mdiff[1] = (cscore, jscore)
    # for c in st:
    #     if ret == '':
    #         ret += c
    #     elif c >= ret[0]:
    #         ret = c + ret
    #     else:
    #         ret = ret + c
    ret = ' '.join(mdiff[1])
    return ret


def main():
    import sys
    infile = read(sys.argv[1])
    outfilename = sys.argv[2]
    def it():
        return next(infile)

    T = int(it())

    with open(outfilename, 'w') as outfile:
        for caseidx in range(1, T+1):
            S = it()
            ans = calc(S)
            outfile.write('Case #{}: {}\n'.format(caseidx, ans))
            print('Case #{}: {}'.format(caseidx, ans))


if __name__ == '__main__':
    main()
