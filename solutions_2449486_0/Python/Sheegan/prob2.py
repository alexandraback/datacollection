def check_row(field,i):	
	#returns True if possible
	return not '2' in field[i]

def check_collum(field,j,N):
	for i in range(N):
		if field[i][j] == '2':
			return False
	return True

def can_they(field, N, M):
#	uncut = True
#	for line in feild:
#		if '1' in line:
#			uncut=False
#			break
#	if uncut:
#		return "YES"
#
#	for i in range(M):
#		if feild[0][i] == 1:
#			for j in range(N):
#				if feild[j][i] != '1':
#					return "NO"
#	for j in range(N):
#		if feild[j][0] == 1:
#			for i in range(M):
#				if feild[j][i] != '1':
#					return "NO"

	for i in range(N):
		for j in range(M):
			if field[i][j] == '1':
				if not (check_row(field,i) or check_collum(field,j,N)):
					return "NO"
	return "YES"

#print can_they([['2', '2', '2'],['2', '1', '2'],['2', '2', '2']], 3, 3)

f = open("B-small-attempt0.in")
g = open("Output.txt", 'w')
cases = int(f.readline())
for case in range(cases):
#	print "Case " + str(case+1)
	ranges = f.readline()
	N, M = ranges.split()
	N = int(N)
	M = int(M)
	field = []
	for i in range(N):
		grass = f.readline()
		field.append(grass.split())	
	if N == 1 or M == 1:
		result = "YES"
	else:
		result = can_they(field, N, M)
#	for i in range(N):
#		print feild[i]
	g.write("Case #" + str(case+1) + ": " + result + "\n")

