T=int(input())

for case in range(1,T+1):
	inp=list(input())
	inp=sorted(inp)
	number=[]
	while 'Z' in inp:
		inp.remove('Z')
		inp.remove('E')
		inp.remove('R')
		inp.remove('O')
		number.append('0')
	while 'X' in inp:
		inp.remove('S')
		inp.remove('I')
		inp.remove('X')
		number.append('6')
	while 'W' in inp:
		inp.remove('T')
		inp.remove('W')
		inp.remove('O')
		number.append('2')
	while 'S' in inp:
		inp.remove('S')
		inp.remove('E')
		inp.remove('V')
		inp.remove('E')
		inp.remove('N')
		number.append('7')
	while 'V' in inp:
		inp.remove('F')
		inp.remove('I')
		inp.remove('V')
		inp.remove('E')
		number.append('5')
	while 'G' in inp:
		inp.remove('E')
		inp.remove('I')
		inp.remove('G')
		inp.remove('H')
		inp.remove('T')
		number.append('8')
	while 'T' in inp:
		inp.remove('T')
		inp.remove('H')
		inp.remove('R')
		inp.remove('E')
		inp.remove('E')
		number.append('3')
	while 'F' in inp:
		inp.remove('F')
		inp.remove('O')
		inp.remove('U')
		inp.remove('R')
		number.append('4')
	while 'O' in inp:
		inp.remove('O')
		inp.remove('N')
		inp.remove('E')
		number.append('1')
	while 'N' in inp:
		inp.remove('N')
		inp.remove('I')
		inp.remove('N')
		inp.remove('E')
		number.append('9')

	
	number=sorted(number)
	output="".join(number)
	print("Case #%d: %s" %(case,output) )

