
import sys

if __name__ == "__main__":
	
	fin = open(sys.argv[1], 'r')
	
	data = fin.readlines()
	
	total = int(data[0])
	
	for case in range(1, total + 1):
		ans = 0;
		target = int(data[case]);
		
		f = [i for i in range(target+1)]

		for i in range(1, target + 1):
			
			i_str = str(i)[::-1]
			f[i] = f[i-1] + 1;
			
			if (i_str[0] != '0' and int(i_str) < i):
				f[i] = min(f[i - 1] , f[int(i_str)]) + 1;
			
			#print i, f[i]
			
		print "Case #" + str(case) + ":", f[target]