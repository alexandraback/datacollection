import fileinput
import sys
import math

def ex1C(line):
	(r,c,w) = [int(x) for x in line.split()]
	checks_on_one_line = c / w
	checks_all_grid = checks_on_one_line * r
	required_checks = checks_all_grid + w - 1
	if(c%w != 0):
		required_checks += 1
	return required_checks

if __name__ == '__main__':
	ncases = int(sys.stdin.readline())
	for i in range(1, ncases + 1 ):
		print "Case #{0}: {1}".format(i, ex1C(sys.stdin.readline().rstrip()))
    	

    	
