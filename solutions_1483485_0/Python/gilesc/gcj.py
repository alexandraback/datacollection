import fileinput
import pprint

k = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee"
v = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo"
mapping = dict(zip(list(k),list(v)))
mapping['z'] = 'q'
#alphabet = set(map(chr, range(97,97+25)))
#print set(alphabet).difference(mapping.values())

def translate(text):
	return "".join(map(mapping.get, list(text)))

#print translate("a zoo")
lines = fileinput.input()
lines.next()
for i,line in enumerate(lines):
	print "Case #%d:" % (i+1), translate(line.strip())

