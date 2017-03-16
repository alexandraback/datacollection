# -*- coding: cp1252 -*-
#https://code.google.com/codejam/contest/6254486/dashboard#s=p1
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


def contaViradas(s):
    ant = None
    if logDet: print 'contaViradas:',s
    viradas = 0
    for ch in s:
        if logDet: print ant,ch,viradas,
        if ch != ant:
            viradas += 1
            ant = ch
        if logDet: print viradas

    #se o ultimo eh + nao precisa ultima virada
    if s[-1] == '+':
        viradas -= 1

    return viradas
    



##nomeIn = "example.txt"
nomeIn = "B-small-attempt0.in"
##nomeIn = "B-large.in"

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

    S = fin.readline()
    S = S.replace("\n","")


    res = contaViradas(S)

    log = "Case #%d: %d"%(case, res)

    fout.write(log)
    print "<%s> %s"%(S, log)

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
