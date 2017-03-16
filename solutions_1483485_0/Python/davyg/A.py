
b = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""

g = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""

m = {'q' : 'z', 'z' : 'q'}

alpha = "abcdefghijklmnopqrstuvwxyz"

for i in range(0, len(b)):
	m[b[i]] = g[i]

N = int(raw_input())
for i in range(0, N):
	s = raw_input()
	r = ""
	for c in s:
		r += m[c] 
	print("Case #{i}: {r}".format(i=i+1,r=r))
