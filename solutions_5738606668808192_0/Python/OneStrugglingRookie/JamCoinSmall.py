from math import sqrt
import os

def pFactors(n):
    """Finds one nontrivial factor 'n'"""

    flag = False
    pFact, limit, check, num = [], int(sqrt(n)) + 1, 2, n
    if n == 1: return False,1
    for check in range(2, limit):
        if num % check == 0:
            flag = True
            break
    return flag, check


def nontrivialFactor(coin,base):

    val = 0
    t = 0
    for bit in coin[::-1]:
        if bit == '1':
            val += base**t
        t += 1
    Feasible, check = pFactors(val)
    return Feasible, check


def nontrivialFactorAll(coin):

    Check = []
    Flag = True
    for base in range(2,11):
        flag,check = nontrivialFactor(coin,base)
        if flag:
            Check.append(check)
        else:
            Flag = False
            break
    return Flag,Check



def EnumerateAll(J):

    os.remove('Bits16.out')
    count = 0
    output = open('Bits16.out','a')
    output.write('Case #1:\n')
    # 2**16+1
    for val in xrange(2**15,2**16-1):
        coin = "{0:016b}".format(val)
        if coin[0] != '1' or coin[-1] != '1':
            continue

        Flag,Check = nontrivialFactorAll(coin)
        if Flag :
            count += 1
            print count
            checkstr = ''
            for s  in Check:
                checkstr = checkstr + ' '+str(s)
            writeLine = coin + checkstr+'\n'
            output.write(writeLine)
            if count >= J:
                break
    output.close()

f = open('C-small-attempt1.in', 'r')
Data = f.read()
Data = Data.split('\n')
Data = Data[1]

N = int(Data[0:2])
J = int(Data[2:5])
print N
print J
if N == 16 and J == 50:
    print 'File Production Begins'
    EnumerateAll(50)
    print 'File Producation Completed'