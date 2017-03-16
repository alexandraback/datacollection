import argparse
import numpy as np

def fix_count(a,n,sizes):
	print "NEW##"

	if a <= 1:
		return n


	sizes.sort()

	print "List:"
	print  sizes
	adds = np.zeros(n)
	removes = 0

	for i in range(n):

		print "Have %d"%a
		print "at %d"%sizes[i]
		if a>sizes[i]:
			a += sizes[i]
		else:
			#add or remove


			#how many adds needed?
			temp = a 
			count = 0
			if temp != 1:
				while temp <= sizes[i]:
					temp += temp-1
					count += 1
			else:
				count = len(sizes)+1


			print "adding %d"%count
			adds[i] = count
			a = temp+sizes[i]






	# check for remove
	print adds
	adds = adds[::-1]
	cs = np.cumsum(adds)
	r=np.arange(n)+1

	d = cs-r
	print cs
	print r
	cut = np.where(cs>r)[-1]

	if len(cut)>0:
		cut = cut[0]
		return int(cut+1+sum(adds[cut+1:]))
	else:
		return int(cs[-1])


	
	return n



	


if __name__=='__main__':
	
	
	p = argparse.ArgumentParser(description='adsf')
	p.add_argument('infilename', nargs=1, help='ncs file to be converted')
	p.add_argument('outfilename', nargs=1, help='ncs file to be converted')

	args = p.parse_args()


	inf = open(args.infilename[0])
	outf = open(args.outfilename[0],'w')


	num = inf.readline()


	for i in range(int(num)):

		(a,n) = [long(d) for d in inf.readline().split()]

		sizes = [long(d) for d in inf.readline().split()]


		out = fix_count(a,n,sizes)
		print out
		outf.write('Case #%d: %d\n'%((i+1),out))
	

