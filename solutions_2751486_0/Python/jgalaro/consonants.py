import argparse
import numpy as np


VOWELS =['a','e','i','o','u']

def ss_count(name,n):
	lname = list(name)

	count = 0

	for start in range(len(lname)):
		for stop in range(start,len(lname)):
			#print "Start %d, Stop %d, word %s" %(start,stop,name)
		
			test = [a not in VOWELS for a in lname[start:stop+1]]

			inRow = 0
			
			for t in test:
				if t:
					inRow += 1
					if inRow >= n:
						count += 1
						break
				else:
					inRow = 0

	return count







if __name__=='__main__':
	
	
	p = argparse.ArgumentParser(description='adsf')
	p.add_argument('infilename', nargs=1, help='ncs file to be converted')
	p.add_argument('outfilename', nargs=1, help='ncs file to be converted')

	args = p.parse_args()


	inf = open(args.infilename[0])
	outf = open(args.outfilename[0],'w')


	num = inf.readline()


	for i in range(int(num)):

		(name,n) = [d for d in inf.readline().split()]

		n = int(n)




		out = ss_count(name,n)

		outf.write('Case #%d: %d\n'%((i+1),out))
	

