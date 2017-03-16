def A(P,Q):
	count  = 0
	flag = True
	while True:
		if (P >= Q):
			if flag:
				ans = count
				flag = False
			if (P == Q): 
				return ans
			P = P -Q
		if (Q % 2 == 0):
			Q = Q / 2
			count +=1
		else:
			return -1

def main():
	fin = open("A-large.in")
	fout = open("out.txt","w")

	cases = int(fin.readline())
	for case in range(cases):
		print case
		line = fin.readline().replace("\n","").split("/")
		ans = A(int(line[0]),int(line[1]))
		if (ans == -1):
			fout.write("Case #"+str(case+1)+": impossible\n")
		else:
			fout.write("Case #"+str(case+1)+": "+str(ans)+"\n")


	fin.close()
	fout.close()
main()