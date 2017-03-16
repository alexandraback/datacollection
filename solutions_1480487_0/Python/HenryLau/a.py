import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')

def main():
	fn = raw_input('File name: ')
	fin = open(fn)
	o = open('output.txt','w')
	no_iter = int(fin.readline())
	for x in xrange(no_iter):
		para = fin.readline().replace("\n",'').split(' ')
		result = a(map(int,para))
		o.write("Case #"+str(x+1) + ": " + result + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_iter) +"Done")
	fin.close()
	o.close()

def shift(i):
	return str(i)[-1] + str(i)[0:-1]

def a(ls):
	no_player = ls[0]
	jp = ls[1:]
	lsum = sum(jp)
	ap = [(2./no_player - float(i)/lsum)*100 for i in jp]
	pos = [1 if i >= 0 else 0 for i in ap]
	sp = sum(pos)
	if sp != len(jp):
		res = sum([i for i in ap if i <0])
		logging.debug(res)
		ls = [i + res* j/sp if i >0 else 0 for i,j in zip(ap,pos)]
	else:
		ls = ap
	return " ".join(map(str,ls))

main()