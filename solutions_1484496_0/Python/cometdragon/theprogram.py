import itertools

fin = open("C-small-attempt0-1.in.txt")
fout = open("output.out",'w')
number = int(fin.readline())
casenum = 1

while casenum <= number:

	a = str(fin.readline())[3:]

	def master(a):

		listed = []
		list = []
		blank = ""
		status = False

		for i in a:
			if i == " ":
				listed.append(int(blank))
				blank = ""
			blank += i

		n = 1

		while True:
			for i in itertools.combinations(listed, n):
				if sum(i) not in list:
					list.append(sum(i))
					list.append(i)
				else:
					return list[list.index(sum(i))+1], i
			n += 1
		
	encase = "Case #" + str(casenum) + ":" + "\n"
	
	fout.write(encase)
		
	for i in master(a):
		for x in i:
			fout.write(str(x))
			if i.index(x) != len(i)-1:
				fout.write(" ")
		fout.write("\n")
			
	casenum += 1
	
fin.close()
fout.close()