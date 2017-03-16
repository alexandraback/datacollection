import sys
import math



def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())


	for t in range(T):
		CFX = f.readline().strip().split(' ');
		C = float(CFX[0])
		F = float(CFX[1])
		X = float(CFX[2])
		
		cur_time = 0
		cur_rate = 2.0		
		exp_time1 = cur_time + (X/cur_rate)
		exp_time2 = cur_time + (C/cur_rate) + (X/(cur_rate + F))

		while exp_time1>exp_time2:
			cur_time += (C/cur_rate)
			cur_rate += F
			exp_time1 = cur_time + (X/cur_rate)
			exp_time2 = cur_time + (C/cur_rate) + (X/(cur_rate + F))
		
		of.write('Case #'+str(t+1) + ': ' + str(exp_time1)+'\n')

	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

