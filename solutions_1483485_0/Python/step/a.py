import os,sys,fileinput

test_index = -1

m = {}

def assign_map( goog, normal ):
	for pairs in zip(normal,goog):
		(n,g) = pairs
		if not n in m:
			m[n] = g
	assert translate(normal) == goog

def translate( norm ):
	result = ""
	for ch in norm:
		result += m[ch]
	return result


assign_map("a zoo","y qee")
assign_map("our language is impossible to understand","ejp mysljylc kd kxveddknmc re jsicpdrysi")
assign_map("there are twenty six factorial possibilities","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd")
assign_map("so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv")
assign_map("z","q")
assign_map("q","z")

for ch in "abcdefghijklmopqrstuvxywzjk":
	if not ch in m:
		print "Missing", ch
	if not ch in m.values():
		print "Missing values", ch


for line in fileinput.input():
	test_index+=1
	if test_index == 0:
		continue
	line = line[:-1]

	result = translate(line)
	print "Case #%d: %s" % (test_index, result)
