# -*- coding: utf-8 -*-
"""
Created on Sat May 07 10:07:30 2011

@author: Shahar
"""
import string


def A(inpfile):
    #First learn the language
    fin1 = open('..\\test\\learn.txt', 'r')
    Translate = {}
    CNT = int(fin1.readline())
    for iCNT in xrange(CNT):
        Googlerese = fin1.readline().rstrip('\n')
        English = fin1.readline().rstrip('\n')
        for l in range(len(Googlerese)) :
            Translate[Googlerese[l]] = English[l]
    all_letters = list(string.ascii_lowercase)
    all_letters.append(' ')
    for l in Translate.values():
        #print l, all_letters
        all_letters.remove(l)
    Translate['z'] = all_letters[0]
        
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Googlerese = fin.readline().rstrip('\n')
        English = []
        for l in range(len(Googlerese)) :
            English.append(Translate[Googlerese[l]])
            
        text = 'Case #' + str(iCNT+1) + ': ' + reduce(lambda x,y: x+y, English)
        print text
        fout.write(text + '\n')

if __name__ == "__main__":
    #A(sys.argv[1]);
    #A('..\\test\\A-test.in');
    #A('..\\test\\A-small-attempt0.in');
    A('..\\test\\A-small-attempt1.in');
    #A('..\\test\\A-large.in');
