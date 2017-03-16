import sys

def convert(dic, before):
	l = len(before)
	result = ""
	for i in range(0, l):
		result += dic[before[i]]
	return result

def train(dic, before, after):
	l = len(before)
	for i in range(0, l):
		b = before[i]
		a = after[i]
		dic[b] = a
	return dic


def main(argv):
	dic = {}
	init1 = "abcdefghijklmnopzrstuvwxyq"
	init2 = "abcdefghijklmnopqrstuvwxyz"
	before1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
	before2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
	before3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv"
	after1 = "our language is impossible to understand"
	after2 = "there are twenty six factorial possibilities"
	after3 = "so it is okay if you want to just give up"
	train(dic, init1, init2)
	train(dic, before1, after1)
	train(dic, before2, after2)
	train(dic, before3, after3)
	f = open(argv[0])
	count = int(f.readline().strip())
	for i in range(1, count+1):
		line = f.readline().strip()
		print "Case #"+str(i)+": " + convert(dic, line)
	f.close()


if __name__=="__main__":
	main(sys.argv[1:])
