#if only for the 10 points

from math import sqrt
from sys import stdin, stdout, argv

fin = open(argv[1]) if len(argv) > 1 else stdin
fout = open(argv[2]) if len(argv) > 2 else stdout

# precalculated list of the square roots of nums such that
# x is a palindrome and x**2 is a palindrome
fsr_nums = [1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 
	10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 
	110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 
	1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 
	10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 
	11111111, 20000002, 100000001, 100010001, 100020001, 100101001, 
	100111001, 100121001, 101000101, 101010101, 101020101, 101101101, 
	101111101, 110000011, 110010011, 110020011, 110101011, 110111011, 
	111000111, 111010111, 111101111, 111111111, 200000002, 200010002]
fs_nums = [x**2 for x in fsr_nums]


N = int(fin.readline())
for case in xrange(1, N + 1):
	a, b = map(int, fin.readline().split())
	t = sum(1 for n in fs_nums if n >= a and n <= b)
	fout.write('Case #%d: %d\n' % (case, t))
