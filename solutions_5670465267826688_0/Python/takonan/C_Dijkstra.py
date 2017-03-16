import sys, math

quadProd = {
			'1':{'i':'i', 'j':'j','k':'k'},
			'i':{'i':'-1', 'j':'k','k':'-j'},
			'j':{'i':'-k', 'j':'-1','k':'i'},
			'k':{'i':'j', 'j':'-i','k':'-1'},
			'-1':{'i':'-i', 'j':'-j','k':'-k'},
			'-i':{'i':'1', 'j':'-k','k':'j'},
			'-j':{'i':'k', 'j':'1','k':'-i'},
			'-k':{'i':'-j', 'j':'i','k':'1'},
		}

def cumProd(LX_list, indx):
	""" Returns the cumulative product up to indx
	"""

	if indx == 0:
		return LX_list[0]
	else:
		prod = LX_list[0]
		for i in range(1, indx + 1):
			prod = quadProd[prod][LX_list[i]]
		return prod

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		L, X = map(int, fin.readline().strip().split())
		# print L, X
		L_list = list(fin.readline().strip())
		# print L_list
		LX_list = L_list * X
		# print LX_list

		#Sanity checks
		if len(LX_list) < 3:
			# print "Length less than 3, can't partition into 3!"
			answer = 'NO'
		else:
			# Find the index where the cumulative prod is i
			prod = LX_list[0]
			I_list = []
			if prod == 'i':
				I_list.append(0)
			for i in range(1, L*X - 1):
				# print "At index %d: " % i
				prod = quadProd[prod][LX_list[i]]
				if prod == 'i':
					I_list.append(i)
			# print "I_list: " + str(I_list)
			# If I_list empty then answer is no
			if len(I_list) == 0:
				answer = 'NO'
			else:
				# Find the index where the cumulative prod is k
				prod = 'i'
				J_list = []
				for i in range(I_list[0]+1, L*X - 1):
					# print "At index %d: " % i
					prod = quadProd[prod][LX_list[i]]
					if prod == 'k':
						J_list.append(i)
				print "J_list: " + str(J_list)
				if len(J_list) == 0:
					answer = 'NO'
				else:
					prod = 'k'
					for i in range(J_list[-1]+1, L*X):
						# print "Checking for i at index %d" % i
						prod = quadProd[prod][LX_list[i]]
					if prod == '-1':
						answer = 'YES'
					else:
						answer = 'NO'
		print "Case #%d: %s" % (t+1, answer)
		fout.write("Case #%d: %s\n" % (t+1, answer))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
