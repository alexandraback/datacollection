import sys
import string

f = "abcdefghijklmnopqrstuvwxyz"
t = "yhesocvxduiglbkrztnwjpfmaq"

with open(sys.argv[1], 'r') as input:
	n = int(input.readline())
	for i in range(n):
		line = input.readline().rstrip()
		print 'Case #{}: {}'.format(i+1, line.translate(string.maketrans(f, t)))
		