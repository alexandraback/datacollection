#!/usr/bin/python

k = 'yeq\
ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv'
v = 'aoz\
our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up'

d = {k[i]:v[i] for i in xrange(len(k))}

d['z'] = [c for c in list('abcdefghijklmnopqrstuvwxyz') if c not in set(v)][0]

t = input()

for i in xrange(1, t+1):
	s = ''.join([d[k] for k in raw_input()])
	print 'Case #{0}: {1}'.format(i, s)
