import itertools
import time
import operator
#import collections
from collections import Counter
from itertools import repeat

#inputFileName = "test.in"
#inputFileName = "C-small-attempt0.in"
#inputFileName = "C-small-attempt1.in"
#inputFileName = "C-small-attempt2.in"
#inputFileName = "C-small-attempt3.in"
inputFileName = "C-small-attempt4.in"

#inputFileName = "C-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def crete_mul_dict():
    mul_dict0 = dict()
    mul_dict_1 = dict()
    mul_dict_1['1'] = '1'
    mul_dict_1['i'] = 'i'
    mul_dict_1['j'] = 'j'
    mul_dict_1['k'] = 'k'
    mul_dict0['1'] = mul_dict_1

    mul_dict_i = dict()
    mul_dict_i['1'] = 'i'
    mul_dict_i['i'] = '-1'
    mul_dict_i['j'] = 'k'
    mul_dict_i['k'] = '-j'
    mul_dict0['i'] = mul_dict_i

    mul_dict_j = dict()
    mul_dict_j['1'] = 'j'
    mul_dict_j['i'] = '-k'
    mul_dict_j['j'] = '-1'
    mul_dict_j['k'] = 'i'
    mul_dict0['j'] = mul_dict_j

    mul_dict_k = dict()
    mul_dict_k['1'] = 'k'
    mul_dict_k['i'] = 'j'
    mul_dict_k['j'] = '-i'
    mul_dict_k['k'] = '-1'
    mul_dict0['k'] = mul_dict_k
    return mul_dict0

mul_dict = crete_mul_dict()

allowed = dict()
allowed['1'] = False
allowed['i'] = False
allowed['j'] = False
allowed['k'] = False
allowed['-1'] = False
allowed['-i'] = False
allowed['-j'] = False
allowed['-k'] = False

def mul(q1, q2):
    inv = allowed[q1] and allowed[q2]
#    inv = False
    if q1[0] == '-':
        inv = not inv
        q1 = '' + q1[1]
    if q2[0] == '-':
        inv = not inv
        q2 = '' + q2[1]
    res = mul_dict[q1][q2]
    if inv:
        if res[0] == '-':
            res = '' + res[1]
        else:
            res = '-' + res
    return res


def pow_q(q1, p):
    res = '1'
    for i in xrange(0, p):
        res = mul(res, q1)
    return res


def eval_q(s):
    if len(s) == 0:
        raise RuntimeError("CCCC")
    res = '1'
    for m in s:
        res = mul(res, m)
    return res

def calcSingleTest(f):
    line = f.readline()
    L = int(line.split()[0])
    X = int(line.split()[1])
    line = f.readline()[0:L]
#    line = f.readline()[:-1]
#    if L != len(line):
#        raise RuntimeError("AAAAAA")

    line_res = eval_q(line)
    total_res = pow_q(line_res, X)
    print str(X) + ' * ' + line
    print line_res
    print 'total res = ' + total_res
    if len(line) == 1:
        return "NO"
    if total_res != '-1':
        return "NO"
    #r = min(30, X)
    r = X
    base_line = ''.join(repeat(line, r))
    rest_line_res = '1' if X < r else pow_q(line_res, X - r)
    print base_line
    print rest_line_res

    res_i = '1'
    res_j = '1'
    #res_k = '1'
    pos_i = pos_j = -1
    base_len = len(base_line)
    for pos_i in xrange(0, base_len):
        res_i = mul(res_i, base_line[pos_i])
        if res_i == 'i':
            break
    pos_i += 1
    if base_len == pos_i:
        print '1 !!!'
        return "NO"

    for pos_j in xrange(pos_i, base_len):
        res_j = mul(res_j, base_line[pos_j])
        if res_j == 'j':
            break
    pos_j += 1
    if base_len == pos_j:
        print '2 !!!'
        return "NO"

    base_rest = base_line[pos_j:]
    base_rest_res = eval_q(base_rest)
    res_k = mul(base_rest_res, rest_line_res)

    print "i = " + eval_q(base_line[0:pos_i]) + " - " + base_line[0:pos_i]
    print "j = " + eval_q(base_line[pos_i:pos_j]) + " - " + base_line[pos_i:pos_j]

    if res_k != 'k':
        print '3 !!!!!!!!!!!!!!!!!!!!!!!!!'
        raise RuntimeError("BBBBB")
        return "NO"

    #    print "i = " + eval_q(base_line[0:pos_i]) + " - " + base_line[0:pos_i]
    #    print "j = " + eval_q(base_line[pos_i:pos_j]) + " - " + base_line[pos_i:pos_j]
    return "YES"

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            res = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, res))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))