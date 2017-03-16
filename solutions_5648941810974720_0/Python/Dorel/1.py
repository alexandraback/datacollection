
T=int(raw_input())

for test in xrange(1,T+1) :
	s=raw_input().rstrip()
	ans=''
	while 'Z' in s : 
		s=s.replace('Z','',1)
		s=s.replace('E','',1)
		s=s.replace('R','',1)
		s=s.replace('O','',1)
		ans+='0'
	while 'W' in s : 
		s=s.replace('T','',1)
		s=s.replace('W','',1)
		s=s.replace('O','',1)
		ans+='2'
	while 'U' in s : 
		s=s.replace('F','',1)
		s=s.replace('O','',1)
		s=s.replace('U','',1)
		s=s.replace('R','',1)
		ans+='4'
	while 'X' in s : 
		s=s.replace('S','',1)
		s=s.replace('I','',1)
		s=s.replace('X','',1)
		ans+='6'
	while 'G' in s : 
		s=s.replace('E','',1)
		s=s.replace('I','',1)
		s=s.replace('G','',1)
		s=s.replace('H','',1)
		s=s.replace('T','',1)
		ans+='8'
	while 'O' in s : 
		s=s.replace('O','',1)
		s=s.replace('N','',1)
		s=s.replace('E','',1)
		ans+='1'
	while 'H' in s : 
		s=s.replace('T','',1)
		s=s.replace('H','',1)
		s=s.replace('R','',1)
		s=s.replace('E','',1)
		s=s.replace('E','',1)
		ans+='3'
	while 'F' in s : 
		s=s.replace('F','',1)
		s=s.replace('I','',1)
		s=s.replace('V','',1)
		s=s.replace('E','',1)
		ans+='5'
	while 'S' in s : 
		s=s.replace('S','',1)
		s=s.replace('E','',1)
		s=s.replace('V','',1)
		s=s.replace('E','',1)
		s=s.replace('N','',1)
		ans+='7'
	for x in xrange(len(s)/4) : ans+='9'
	print "Case #%d: "%test,''.join(sorted(ans))  

