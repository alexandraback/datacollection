import string
g = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'
e = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'
d = {}
for ge,ee in zip(g,e):
	if ge not in d:
		d[ge] = ee
	else:
		if d[ge] != ee:
			print 'ge:',ge,', d[ge]:',d[ge],', ee:',ee

if 'a' not in d:d['a'] = 'y'
if 'o' not in d:d['o'] = 'e'
if 'z' not in d:d['z'] = 'q'

for l in string.lowercase[:26]:
    if l not in d.keys(): print 'missing',l,'in in'
    if l not in d.values(): print 'missing',l,'in out'


d['q'] = 'z'

trans = lambda l:d[l]

print'Enter input:'
cases = raw_input().split('\n')
print cases[0],'test cases'
cases.pop(0)
for i,c in enumerate(cases):
    print 'Case #'+str(i+1)+':',
    print ''.join(map(trans,c))
