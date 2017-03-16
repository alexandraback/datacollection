def solve(s):
	digits = []
	while 'Z' in s:
		digits.append('0')
		s = s.replace('Z','',1)
		s = s.replace('E','',1)
		s = s.replace('R','',1)
		s = s.replace('O','',1)
	while 'W' in s:
		digits.append('2')
		s = s.replace('T','',1)
		s = s.replace('W','',1)
		s = s.replace('O','',1)
	while 'U' in s:
		digits.append('4')
		s = s.replace('F','',1)
		s = s.replace('O','',1)
		s = s.replace('U','',1)
		s = s.replace('R','',1)
	while 'X' in s:
		digits.append('6')
		s = s.replace('S','',1)
		s = s.replace('I','',1)
		s = s.replace('X','',1)
	while 'G' in s:
		digits.append('8')
		s = s.replace('E','',1)
		s = s.replace('I','',1)
		s = s.replace('G','',1)
		s = s.replace('H','',1)
		s = s.replace('T','',1)
	while 'H' in s:
		digits.append('3')
		s = s.replace('T','',1)
		s = s.replace('H','',1)
		s = s.replace('R','',1)
		s = s.replace('E','',1)
		s = s.replace('E','',1)
	while 'S' in s:
		digits.append('7')
		s = s.replace('S','',1)
		s = s.replace('E','',1)
		s = s.replace('V','',1)
		s = s.replace('E','',1)
		s = s.replace('N','',1)
	while 'V' in s:
		digits.append('5')
		s = s.replace('F','',1)
		s = s.replace('I','',1)
		s = s.replace('V','',1)
		s = s.replace('E','',1)
	while 'O' in s:
		digits.append('1')
		s = s.replace('O','',1)
		s = s.replace('N','',1)
		s = s.replace('E','',1)
	digits = digits + ['9'] * (len(s)/4)
	return ''.join(sorted(digits))



if __name__ == "__main__":
	testcases = input()

	for caseNr in xrange(1, testcases+1):
		cipher = raw_input()
		print("Case #%i: %s" % (caseNr, solve(cipher)))