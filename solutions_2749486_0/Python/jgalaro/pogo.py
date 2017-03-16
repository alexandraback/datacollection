import argparse
import numpy as np


def find_path(x,y):
	max_step = 0

	solved = False

	while not solved:
		max_step += 1
		tx = x
		ty = y
		templ = []
		for s in np.arange(max_step,0,-1):
			if(abs(tx)>abs(ty)):
				if(tx<0):
					tx+=s
					templ.append('W')
				else:
					tx-=s
					templ.append('E')
			else:
				if(ty<0):
					ty+=s
					templ.append('S')
				else:
					ty-=s
					templ.append('N')
		if tx==0 and ty==0:
			solved = True
	
	templ.reverse()
	return templ






if __name__=='__main__':
	
	
	p = argparse.ArgumentParser(description='adsf')
	p.add_argument('infilename', nargs=1, help='ncs file to be converted')
	p.add_argument('outfilename', nargs=1, help='ncs file to be converted')

	args = p.parse_args()


	inf = open(args.infilename[0])
	outf = open(args.outfilename[0],'w')


	num = inf.readline()


	for i in range(int(num)):

		(x,y) = [int(d) for d in inf.readline().split()]





		out = find_path(x,y)
		print out

		outf.write('Case #%d: %s\n'%((i+1),''.join(out)))
	

