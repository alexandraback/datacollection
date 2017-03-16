# -*- coding: cp1252 -*-
#https://code.google.com/codejam/contest/6254486/dashboard
import math
import datetime
import random
import multiprocessing

logDet = False
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


def preencheDigitos(digits, tent):
    st = str(tent)
    if logDet: print 'preencheDigitos',tent, st,
    for digit in st:
        digits[digit] = 1

    if logDet: print sorted(digits.keys())



##nomeIn = "example.txt"
##nomeIn = "A-small-attempt0.in"
nomeIn = "A-large.in"

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

    N = readInt(fin) #N

    digits = {}
    tent = 0
    res = 'None'
    if N == 0:
        res =  'INSOMNIA'
    else:
        itent = 1
        while len(digits) < 10:
            tent = itent * N
            preencheDigitos(digits, tent)
            itent += 1

        res = str(tent)
    



    log = "Case #%d: %s"%(case, res)

    fout.write(log)
    print N, log

    case += 1
    if case > T:
        print "encerrando"
        break

    fout.write("\n")    

    if teste:
        break


fout.close()
##print "FIM"

tfim = datetime.datetime.now()
print "TEMPO GASTO"
print tini
print tfim
print tfim-tini
