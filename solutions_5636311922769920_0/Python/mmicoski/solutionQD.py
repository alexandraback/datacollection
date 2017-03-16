# -*- coding: cp1252 -*-
#https://code.google.com/codejam/contest/6254486/dashboard#s=p1
import math
import datetime
import random
import multiprocessing
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

#================================
def qtStudents(K,C):
    if K == 0:
        return 0
    if C == 0:
        return 0
    
    K = int(K)
    C = int(C)
    S = K/C
    if (K%C) != 0:
        S += 1
    return S

def inteiro(diglist, base):
    tam = len(diglist)
    mult = 1
    total = 0
    for i in range(1,tam+1):
        if diglist[-1] < 0 or diglist[-1] >= base:
            raise ValueError('digit out of [0, base[ range')
        total = total + diglist[-i]*mult
        mult = mult * base

    return total
        
    
# positions are given by numbers of C digits in base K
# we want to use all K digits
def listaPosicoes(K,C):
    posicoes = []
    if logDet: print "listaPosicoes", K, C

    if K == 0:
        return posicoes
    if C == 0:
        return posicoes

    if K == 1:
        return [1]
        
    digits = range(K)
    if logDet: print "digits", digits
    for ini in range(0, K, C):
        print "ini=",ini
        if ini+C <= K:
            dig = digits[ini:ini+C]
        else:
            if (K%C) != 0:
                # not enough digits, repeat last
                dig = digits[-C:]
            else:
                # enough
                break
        numst = "".join([str(x) for x in dig])
        #pos = 1+int(numst,K)
        pos = 1+inteiro(dig, K)
        if logDet: print "dl",dig,pos
        posicoes.append(pos)

        
    return posicoes

def subst(orig, seqAtual):
    novaSeq = ""
    ogold = "".join(['G' for x in orig])
    for ch in seqAtual:
        if ch == "G":
            novaSeq += ogold
        else:
            novaSeq += orig

    return novaSeq


def geraSequencias(K, C):
    seqs = []
    for i in range(K):
        seqIni = ['L' for j in range(i)]
        seqIni.append('G')
        seqIni.extend(['L' for j in range(i+1,K)])
        seqIni = "".join(seqIni)
        print "seqIni", seqIni
        seq = seqIni
        for k in range(C-1):
            seq = subst(seqIni, seq)
            

        seqs.append(seq)

    print "sequencias:"
    print len(seqs),"sequencias de",len(seqs[0]), "caracteres"
    a = raw_input("s <ENTER> PARA IMPRIMIR: ")
    print "você escolheu",a
    if a.lower() == 's':
        for item in seqs:
            print item
    return seqs
#================================


##nomeIn = "example.txt"
nomeIn = "D-small-attempt0.in"
##nomeIn = "D-large.in"

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

    kcs = readIntList(fin)
    K = kcs[0]
    C = kcs[1]
    S = kcs[2]

    if logDet: print "K,C,S=",K,C,S

    snec = qtStudents(K,C)
    if snec > S:
        if logDet: print "nec=",snec,
        res = ' IMPOSSIBLE'
    else:
        pos = listaPosicoes(K,C)
        if len(pos) != snec:
            print "======\nERRO!!! (%d, %d)\n======="%(snec, len(pos))
        res = ""
        for item in pos:
            res += " "+str(item)

    
    log = "Case #%d:%s"%(case, res)

    fout.write(log+"\n")
    print log


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
