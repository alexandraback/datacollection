# -*- coding: utf-8 -*-
"""
Created on Sat May 07 10:49:56 2011

@author: Shahar
"""



def B(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Case = map(int, fin.readline().rstrip('\n').split(' '))
        N = Case[0]
        S = Case[1]
        p = Case[2]
        Googlers = Case[3:]
        y = 0
        for i in range(N) :
            if Googlers[i] >= max(3*p-2,p) :
                y += 1
            elif Googlers[i] >= max(3*p-4,p) and S > 0 :
                y += 1
                S -= 1

        text = 'Case #' + str(iCNT+1) + ': ' + str(y)
        print text
        fout.write(text + '\n')

if __name__ == "__main__":
    #B(sys.argv[1]);
    #B('..\\test\\B-test.in');
    #B('..\\test\\B-small-attempt0.in');
    #B('..\\test\\B-small-attempt1.in');
    B('..\\test\\B-large.in');
