import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
import itertools


def main():
	fn = raw_input('File name: ')
	fin = open(fn)
	o = open('output.txt','w')
	no_iter = int(fin.readline())
	for x in xrange(no_iter):
		para = fin.readline().replace("\n",'').split(' ')
		result = c(map(int,para))
		o.write("Case #"+str(x+1) + ": " + '\n'+ result + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_iter) +"Done")
	fin.close()
	o.close()

def shift(i):
	return str(i)[-1] + str(i)[0:-1]

def c(ls):
	n = ls[0]
	ls = sorted(ls[1:])
	d = {}
	for k in ls:
		d[str(k)] = tuple([k])
	for i in range(2,len(ls)+1):
		for j in itertools.combinations(ls,i):
			if d.get(str(sum(j))):
				return " ".join(map(str,j)) + "\n" + " ".join(map(str,d.get(str(sum(j)))))
			else:
				d[str(sum(j))] = j

main()