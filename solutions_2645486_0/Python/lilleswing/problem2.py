__author__ = 'karl'
import string

def solve(ETop, E, R, values, index):
    if(index == len(values)-1):
        return E * values[index]
    else:
        best = 0
        for i in xrange(0, E+1):
            nE = min([ETop, E-i+R])
            tscore = solve(ETop, nE, R, values, index+1) + values[index]*i
            if tscore > best:
                best = tscore
        return best



if __name__ == '__main__':
    data = map(string.strip, open('/home/karl/PycharmProjects/Code_Jam/problem2/B-small-attempt0.in').readlines())
    fout = open('/home/karl/PycharmProjects/Code_Jam/problem2/small.out', 'w')
    rounds = int(data[0])
    data = data[1:]
    for round in xrange(1,rounds+1):
        E, R, N = map(lambda x: int(x), data[0].split(' '))
        values = map(lambda x: int(x), data[1].split(' '))
        data = data[2:]
        opt = solve(E, E, R, values, 0)
        fout.write("Case #%d: %d\n" % (round, opt))
    fout.close()