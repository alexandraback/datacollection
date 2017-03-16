#!/usr/bin/env python

googlerese='ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z'
englishese='our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q'
d={}
for index in range(len(googlerese)):
    d[googlerese[index]]=englishese[index]
#print d
#print len(d)


#infile=open('input_example.in','r')
infile=open('A-small-attempt0.in','r')
line=infile.readline()
T=int(line)
counter=0
for index in range(T):
    counter = counter + 1
    line=infile.readline().rstrip('\n')
    english=''.join([d[c] for c in line])
    print 'Case #%(c)d: %(cm)s' % {"c":counter,"cm":english}
infile.close()
