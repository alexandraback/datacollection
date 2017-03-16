import sys

def gen_maptable():
	inp = """3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
	exp = """3
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""
	if len(inp) != len(exp):
		raise IOException, "strings length is not equal"
	mapTable = {
		'a': 'y',
		'o': 'e',
		'z': 'q',
		'q': 'z',
	}
	for k,v in enumerate(inp):
		mapTable[v] = exp[k]
	return mapTable

mt=gen_maptable()

inp = open(sys.argv[1]).read().strip()
for ln,line in enumerate(inp.split("\n")[1:]):
	print "Case #%s:"%(ln+1),
	out = ""
	for x in line:
		out += mt[x]
	print out