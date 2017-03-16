file = open("C:\\Users\\Rike\\Documents\\GoogleCodeJam\\b.in", "r")
output = open("C:\\Users\\Rike\\Documents\\GoogleCodeJam\\output.txt", "w")

num_cases = int(file.readline())

def fill_matrix(row, node, matrix):
	if row == len(matrix):
		return
	matrix[row][node] = 1
	for idx in range(1, len(matrix) - node):
		fill_matrix(node, node + idx, matrix)
	return

for i in range(num_cases):
	output.write("Case #" + repr(i + 1) + ":")
	bs, ms = file.readline().strip().split()
	b = int(bs)
	m = int(ms)
	outfilestr = ''
	if m > 2**(b-2):
		print(m, "  ", b, "   ", 2**(b-2), "   ", bin(m))
		output.write(" IMPOSSIBLE\n")
		continue
	if m == 2**(b-2):
		for r in range(b):
			for q in range(b):
				if q > r:
					outfilestr = outfilestr + "1"
				else:
					outfilestr = outfilestr + "0"
			outfilestr = outfilestr + "\n"
		output.write(" POSSIBLE\n")
		output.write(outfilestr.strip() + "\n")
		continue
		
	if b == 2:
		output.write(" POSSIBLE\n01\n00\n")
		continue
	matrix = [[0 for k in range(b)] for i in range(b)]
	
	cur = len(bin(m)[2:])
	#print(bin(m)[2:])
	#print(m)
	for idx in range(len(bin(m)[2:])):
		if bin(m)[2:][idx] == "1":
			fill_matrix(0, idx + (b - 1 - cur), matrix)
	matrix[0][0]= 0
	matrix[0][b - 1] = 0
	for item in matrix:
		for idx in range(len(item)):
			outfilestr = outfilestr + repr(item[idx])
			
		outfilestr = outfilestr + "\n"
	#print(outfilestr)
	
	output.write(" POSSIBLE\n")
	output.write(outfilestr.strip() + "\n")
output.close()
file.close()