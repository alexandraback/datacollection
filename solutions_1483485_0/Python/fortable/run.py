#!/usr/bin/pypy

import sys
dics = {'y':'a', 'e':'o', 'q' : 'z'}
sample_input = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"

sample_out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

def match_fun(str1, str2):
	for i1, i2 in zip(str1,str2):
		dics.update({i1:i2})


def map_fun(str1):
		return "".join(map(lambda x: dics[x], str1))
if __name__=="__main__":
	match_fun(sample_input, sample_out)
	dics.update({'z':'q', '\n':''})
	n = sys.stdin.readline()
	data = sys.stdin.readlines()
	c = 1
	for i in data:
		print "Case #"+str(c)+": " + map_fun(i)
		c += 1
	
