import sys

f_i = open(sys.argv[1], 'r')
f_o = open(sys.argv[2], 'w')

count = int(f_i.readline())
def decode(i):
	if i=='a':
		return 'y'
	if i=='b':
		return 'h'
	if i=='c':
		return 'e'
	if i=='d':
		return 's'
	if i=='e':
		return 'o'
	if i=='f':
		return 'c'
	if i=='g':
		return 'v'
	if i=='h':
		return 'x'
	if i=='i':
		return 'd'
	if i=='j':
		return 'u'
	if i=='k':
		return 'i'
	if i=='l':
		return 'g'
	if i=='m':
		return 'l'
	if i=='n':
		return 'b'
	if i=='o':
		return 'k'
	if i=='p':
		return 'r'		
	if i=='q':
		return 'z'	
	if i=='r':
		return 't'	
	if i=='s':
		return 'n'	
	if i=='t':
		return 'w'	
	if i=='u':
		return 'j'	
	if i=='v':
		return 'p'	
	if i=='w':
		return 'f'	
	if i=='x':
		return 'm'	
	if i=='y':
		return 'a'	
	if i=='z':
		return 'q'
	if i ==' ':
		return ' '
	return i

for i in range(count):
	line = f_i.readline()
	new = ''
	for j in line:
		new = new + decode(j)
	f_o.write('Case #'+str(i+1)+': '+new)