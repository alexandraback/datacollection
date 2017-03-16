src = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'
dst = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'
maps = {'q' : 'z', 'z' : 'q'}
for i in zip(src, dst):
	maps[i[0]] = i[1]

t = input()
for cases in range(t):
	ans = "Case #" + str(cases + 1) + ": "
	que = raw_input()
	for ch in que:
		ans += maps[ch]
	print ans
