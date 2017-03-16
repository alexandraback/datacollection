# -*- coding: utf-8 -*-
"""
Created on Sat May 07 11:45:04 2011

@author: Shahar
"""

from operator import add

def C(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Case = map(int, fin.readline().rstrip('\n').split(' '))
        A = Case[0]
        B = Case[1]
        maxDigits = len(str(B))
        y = 0
        for i in xrange(A,B+1) :
            orgNum = str(i)
            for j in xrange(maxDigits - len(orgNum) + 1) :
                num = j*'0' + orgNum
                recNums = []
                for k in xrange(0,len(num)) :
                    recNums.append(num[k:] + num[:k])
                recNums = set(recNums)
                recNums.remove(num)
                for k in recNums :
                    if int(k) >= A and int(k) <= B :
                        y += 1
        text = 'Case #' + str(iCNT+1) + ': ' + str(y/2)
        print text
        fout.write(text + '\n')
        
if __name__ == "__main__":
    #C(sys.argv[1]);
    #C('..\\test\\C-test.in');
    #C('..\\test\\C-small-attempt0.in');
    #C('..\\test\\C-small-attempt1.in');
    C('..\\test\\C-large.in');
