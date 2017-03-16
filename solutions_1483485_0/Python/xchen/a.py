import sys

def common_init():
	global sout
	sout = sys.stdout.write

def preprocessing():
	global mapa
	l1 = ["ejp mysljylc kd kxveddknmc re jsicpdrysi"
		,"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
		,"de kr kd eoya kw aej tysr re ujdr lkgc jv"]
	l2 = ["our language is impossible to understand"
		,"there are twenty six factorial possibilities"
		,"so it is okay if you want to just give up"]
	mapa = {}
	for i in range(3):
		for j in range(len(l1[i])):
			mapa[l1[i][j]] = l2[i][j]
	mapa['z'] = 'q'
	mapa['q'] = 'z'

def inputing():
	global cas
	global str0
	str0 = raw_input()

def work():
	global str0
	for i in str0:
		if i in mapa:
			sout(mapa[i])
		else :
			print "TIAN"
	sout("\n")

def main():
	n = raw_input();
	n = int(n);
	for i in range(n):
		inputing()
		sout("Case #")
		sout(str(i+1))
		sout(": ")
		work()


common_init()
preprocessing()
main()

