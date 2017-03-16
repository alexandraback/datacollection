__author__ = 'karl'
import string


def factor(g):
    factors = list()
    for i in g:
        if i == 1:
            continue
        efact = list()
        start = 2
        while i != 1:
            count = 0
            flag = False
            while i % start == 0:
                i /= start
                count += 1
                flag = True
            if flag:
                efact.append((start, count))
            start += 1
        factors.append(efact)
    factset = set()
    for factor in factors:
        factset.update(factor)
    digits = list()
    for i in [3, 5]:
        occ = max(filter(lambda x: x[0] == i, factset) + [(i, 0)], key=lambda x: x[1])[1]
        for j in xrange(0, occ):
            digits.append(i)
    occ = any(map(lambda x: x[0] == 2 and x[1] == 1, factset))
    if occ:
        digits.append(2)
    fours = filter(lambda x: x[1] >= 2, filter(lambda x: x[0] == 2, factset))
    twos = filter(lambda x: x[1] == 1, filter(lambda x: x[0] == 2, factset))
    if len(fours) > 0 and len(twos) == 0:
        digits.append(4)
    while(len(digits) < 3):
        digits.append(2)
    return factset, str(digits).replace(', ', '').strip('[]')


if __name__ == '__main__':
    data = map(string.strip, open('/home/karl/PycharmProjects/Code_Jam/problem3/C-small-1-attempt0.in').readlines())[2:]
    fout = open('/home/karl/PycharmProjects/Code_Jam/problem3/small1.out', 'w')
    round = 1
    fout.write("Case #1:\n")
    for dat in data:
        guesses = map(lambda x: int(x), dat.split(' '))
        factset, factors = factor(guesses)
        print factset, factors
        fout.write("%s\n" % factors)
        round += 1
    fout.close()