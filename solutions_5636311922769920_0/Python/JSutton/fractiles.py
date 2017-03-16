infile = open('D-small-attempt0.in', 'r')
outfile = open('D-small-attempt0.out', 'w')

T = int(infile.readline())
print(T)

def solver(N):
	returnstring = ''
	for i in range(1, K):
		returnstring += str(i)
		returnstring += " "
	returnstring += str(K)
	return returnstring

for case in range(T):
	K, C, S = map(int, infile.readline().split())
	solution = solver(K)
	print(solution)
	outfile.write("Case #" + str(case+1) + ": " + str(solution) + "\n")

infile.close()
outfile.close()