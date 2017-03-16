# -*- coding: utf-8 -*-
f = open('dict','r')

data = [line.strip() for line in f.readlines()]

alph_dict = dict([(data[0][i],data[1][i]) for i in range(len(data[0]))])

alph_dict[' '] = ' '

f.close()

f = open('A-small-attempt0.in','r')

count = f.readline().strip()

data = [line.strip() for line in f.readlines()]

f.close()

f = open('A-small-attempt0.out','w')

for c in range(int(count)):
    d = c + 1
    out = 'Case #%d: '%d+''.join([alph_dict[a] for a in data[c]])+'\n'
    #print out
    f.write(out)

f.close()
    


