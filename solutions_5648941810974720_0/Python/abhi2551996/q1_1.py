for i in range(input()):
	print "Case #"+str(i+1)+":",
	a=raw_input().strip	()
	a=list(a)
	s=[]
	#print a
	while len(a):
		if 'Z' in a:
			x='Z'
			while x in a:
				a.remove('Z')
				a.remove('E')
				a.remove('R')
				a.remove('O')
				#print len(a)
				s.append(0)
#				print "0"
#				print a
		if 'W' in a:
			x='W'
			while x in a:
				a.remove('T')
				a.remove('W')
				a.remove('O')
				#a.remove('O')
				s.append(2)
#				print "2"
#				print a

		if 'G' in a:
			x='G'
			while x in a:
				a.remove('E')
				a.remove('I')
				a.remove('G')
				a.remove('H')
				a.remove('T')
				s.append(8)
#				print "8"
#				print a

		if 'X' in a:
			x='X'
			while x in a:
				a.remove('S')
				a.remove('I')
				a.remove('X')
				#a.remove('H')
				#a.remove('T')
				s.append(6)
#				print "6"
#				print a

		if 'U' in a:
			x='U'
			while x in a:
				a.remove('F')
				a.remove('O')
				a.remove('U')
				a.remove('R')
				#a.remove('T')
				s.append(4)
#				print "4"
#				print a

		if 'F' in a:
			x='F'
			while x in a:
				a.remove('F')
				a.remove('I')
				a.remove('V')
				a.remove('E')
				#a.remove('T')
				s.append(5)
#				print "5"
#				print a

		if 'V' in a:
			x='V'
			while x in a:
				a.remove('S')
				a.remove('E')
				a.remove('V')
				a.remove('E')
				a.remove('N')
				s.append(7)
#				print "7"
#				print a

		if 'O' in a:
			x='O'
			while x in a:
				a.remove('O')
				a.remove('N')
				a.remove('E')
				#a.remove('H')
				#a.remove('T')
				s.append(1)
#				print "1"
#				print a

		if 'N' in a:
			x='N'
			#print "x: ",x
			while x in a:
				#print 'j: ',j
				a.remove('N')
				a.remove('I')
				a.remove('N')
				a.remove('E')
				#a.remove('T')
				s.append(9)
#				#print "9"
#				#print a

		if 'T' in a:
			x='T'
			while x in a:
				a.remove('T')
				a.remove('H')
				a.remove('R')
				a.remove('E')
				a.remove('E')
				s.append(3)
#				print "3"
#				print a


	s.sort()
	s=map(str,s)
	s="".join(s)
	print s