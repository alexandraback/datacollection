import itertools
import os.path
import sys
import math
import collections

def process(ifile, ofile):
	test_case_count = int(ifile.readline())
	for test_case_num in range(1, test_case_count + 1):
		P, Q= map(float, ifile.readline().split('/'))
		
		rhs = solve(P, Q)
		ofile.write('Case #{}: {}\n'.format(test_case_num, rhs))
		print 'Case #{}/{}: {}'.format(test_case_num, test_case_count, rhs)
		print

def gcd(a, b): 
	if b == 0: 
		return a 
	else: 
		return gcd(b, a % b) 


def round_down(n):
	ans = 1
	gens = 0
	while ans * 2 <= n:
		gens += 1
		ans *= 2
	return gens
	

def solve(P, Q):
	g = gcd(P, Q)
	P /= g
	Q /= g
	fac = 2**40 // Q
	P *= fac
	Q *= fac
	if Q != 2**40:
		return 'impossible'
	return 40 - round_down(P)
	

def main():
	if len(sys.argv) < 2:
		print 'Usage: {} ex|small|large [num]'.format(os.path.basename(sys.argv[0]))
		sys.exit(1)
	size = sys.argv[1]
	num = sys.argv[2] if len(sys.argv) >= 3 else '0'
	assert size in ('ex', 'small', 'large')
	cyclename = 'A-' + size
	if size != 'ex':
		cyclename += '-{}'.format(num)
	with open('source\\{}.in'.format(cyclename), 'rb') as i:
		with open('source\\{}.out'.format(cyclename), 'wb') as o:
			process(i, o)
		

if __name__ == '__main__':
	main()
