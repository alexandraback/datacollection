# -*- coding: cp1252 -*-
#https://code.google.com/codejam/contest/6254486/dashboard#s=p1
##import math
import datetime
##import multiprocessing
import random as r

logDet = True
teste = False
            
            

def readInt(fin):
    return int(fin.readline())    


def readIntList(fin):
    MN = fin.readline().split()
    MN = [int(x) for x in MN]

    return MN

def readLines(fin, qt):
    lines = []
    for i in range(qt):
        line = fin.readline()
        lines.append(line)

    return lines


# returns False, div when encounters a divisor
def hasNotDivLim(n):
    '''check if integer n has divisors up to limit'''
    # make sure n is a positive integer
    n = abs(int(n))

    # 0 and 1 are not primes
    if n < 2:
        return False, 0

    # 2 is the only even prime number
    if n == 2: 
        return True, None    

    # all other even numbers are not primes, divisable by 2
    if not n & 1: 
        return False, 2

    # range only needs to go up 
    # the square root of n 
    tentatives = int(n**0.5) + 1

    # IMPORTANT: limit the maximum divisor attempted
    # I dont need to know if a number is prime. I need to know if it
    # has dividers
    # the limitation depends on the machine power
    if tentatives > 100000:
        tentatives = 100000
        
    # range starts with 3 and only goes for odd numbers
    for x in range(3, tentatives, 2):
        if n % x == 0:
            return False, x

    return True, tentatives/2



##nomeIn = "example.txt"
##nomeIn = "C-small-attempt0.in"
nomeIn = "C-large.in"

#pth = multiprocessing.Pool(4)

nomeOut = nomeIn.split(".")[0]+".out"
fin = open(nomeIn,"r")
fout = open(nomeOut,"w")


T = readInt(fin)
print T,"tests"



tini = datetime.datetime.now()
print tini
case=1


##quit()



while True:

    nj = readIntList(fin)
    N = nj[0]
    J = nj[1]

    if logDet: print "N,J=",N,J

    encont = 0

    # valor inicial
    a = '1'
    for i in range(N-2):
        a+='0'
    a+= '1'

    # numbers with one identifyed divider in each base
    notprimes = []

    # numbers attempted
    attempted = {}    

    while len(notprimes) < J:
        if logDet: print "tentando", a,
        if a not in attempted:
            # vê se tem um divisor
            dontUse=False
            divs=[]
            for b in range(2,11): #bases from 2 to 10 inclusive
                num = int(a,b)
                ret, div = hasNotDivLim(num)
                if ret == True:
                    if logDet: print (b,'fail'),
                    dontUse = True
                    break
                else:
                    divs.append(div)
                    if logDet: print (b,div),

            if not dontUse:
                notprimes.append([a, divs])
                
            attempted[a] = 1
        else:
            if logDet: print 'repetition',

        print

        # generate new attempt
        # cannot change neither first nor last
        for change in range (3):
            pos = 1+int(r.random()*(len(a)-2))
            ch= '1'
            if a[pos] == '1':
                ch = '0'

        
            a = a[:pos] + ch + a[pos+1:]

    
    log = "Case #%d:"%(case)

    fout.write(log+"\n")

    for item in notprimes:
        log = item[0]
        for div in item[1]:
            log += ' ' + str(div)
            
        fout.write(log+"\n")
        print log
        print item

    case += 1
    if case > T:
        print "encerrando"
        break

    #fout.write("\n")    

    if teste:
        break


fout.close()
##print "FIM"

tfim = datetime.datetime.now()
print "TEMPO GASTO"
print tini
print tfim
print tfim-tini
