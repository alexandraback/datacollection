def osCheck(A, L):
	''' takes current A and remaining L, returns minimum number of L remaining'''
	if not L:
		return 0
	elif A > L[0]:
		return osCheck(A + L[0], L[1:]);
	else:
		#this could be done recursively, but the depth could cause problems
		m = 0
		a = A
		while a <= L[0] and m < len(L): #stops if its added more than the number remaining to remove
			a = a + a - 1
			m = m + 1
		if m >= len(L):
			return len(L)
		else:
			return min(m + osCheck(a + L[0], L[1:]), len(L))

def Osmos(infile="A-small-attempt0.in", outfile="A-small-attempt0.out"):
	f = open(infile, 'r')
	out = open(outfile, 'w')
	
	# get the number of tests
	n = int(f.readline().strip())
	
	for t in range(1, n + 1):
		temp = f.readline().strip().split(' ')
		A = int(temp[0])
		N = int(temp[1])
		temp = f.readline().strip().split(' ')
		L = []
		for n in temp:
			L.append(int(n))
		L.sort()
		#case is now loaded
		
		#answering question
		out.write("Case #" + str(t) + ": " + str(osCheck(A,L)) + "\n")
	
	#closing files
	f.close()
	out.close()
	
	#so I dont need to cat the file after
	f = open(outfile, 'r')
	print f.read()
	f.close()
	
	
if __name__ == "__main__":
    Osmos()