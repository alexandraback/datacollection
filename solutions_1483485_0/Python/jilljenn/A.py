import operator

def fonction(s):
	a = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
	b = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
	c = "de kr kd eoya kw aej tysr re ujdr lkgc jv"
	aa = "our language is impossible to understand"
	bb = "there are twenty six factorial possibilities"
	cc = "so it is okay if you want to just give up"
	vocabulaire = {}
	for i, l in enumerate(a):
		vocabulaire[l] = aa[i]
	for i, l in enumerate(b):
		vocabulaire[l] = bb[i]
	for i, l in enumerate(c):
		vocabulaire[l] = cc[i]
	vocabulaire["z"] = "q"
	vocabulaire["q"] = "z"
	s2 = ""
	for i in s:
		s2 += vocabulaire[i]
	return s2

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		s = input()
		print("Case #{}: {}".format(t + 1, fonction(s)))