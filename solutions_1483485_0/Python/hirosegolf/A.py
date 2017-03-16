

m={}
s1="our language is impossible to understand"
s2="there are twenty six factorial possibilities"
s3="so it is okay if you want to just give up"
for i,c in enumerate("ejp mysljylc kd kxveddknmc re jsicpdrysi"):
	if c in m:
		assert(m[c]==s1[i])
	m[c]=s1[i]
for i,c in enumerate("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"):
	if c in m:
		assert(m[c]==s2[i])
	m[c]=s2[i]
for i,c in enumerate("de kr kd eoya kw aej tysr re ujdr lkgc jv"):
	if c in m:
		assert(m[c]==s3[i])
	m[c]=s3[i]

m["z"]="q"
m["q"]="z"

def ch(c):
	if c.isalnum():return m[c]
	else:return c

def test():
	for c in "abcdefghijklmnopqrstuvwxyz":
		if c not in m:print c
		if c not in m.values():print c
		return "".join(c for c in s if c.isalnum())

def main():
	n=input()
	for i in xrange(n):
		print "Case #%s: %s"%(i+1  , "".join(ch(c) for c in raw_input())) 

main()
