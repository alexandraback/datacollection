
f1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
f2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

d = {}

if __name__ == "__main__":
	
	k = 0
	for i in f1:
		d[i] = f2[k]
		k = k + 1
		
	d['z'] = 'q'
	d['q'] = 'z'
	t = int(raw_input())
	for k in range(1, t+1):
		s = raw_input()
		str = "Case #%d: " % k
		for i in s:
			str = str + d[i]
		print str
