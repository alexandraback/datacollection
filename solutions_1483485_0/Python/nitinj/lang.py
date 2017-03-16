import sys
import string

ttable = string.maketrans('abcdefghijklmnopqrstuvwxyz','yhesocvxduiglbkrztnwjpfmaq')

t = int(sys.stdin.readline())
for i in range(t):
	line = sys.stdin.readline().strip()
	print 'Case #' + str(i+1) + ': ' + line.translate(ttable)
		
		