import sys

def process(dic):
	arr=[]
	for key in dic:
		if dic[key]!=0:
			arr.append(int(key))

	sorted_arr=sorted(arr)
	
	return sorted_arr

def main():
	with open("B-large.in", "r") as ins:
		numOfTestCases=int(ins.readline())
		#print "#cases "+str(numOfTestCases)
		

		cases=[]
		for i in range(numOfTestCases):
			n=int(ins.readline())
			dic = dict()
			
			for j in range(2*n-1):
				line=ins.readline().rstrip()
				numbers=line.split()
				for num in numbers:
					if num in dic:
						dic[num] = (dic[num] +1 )%2
					else:
						dic[num] = 1
					
					#dic[num]=dic[num]+1
				# Case #1: 2 3

			arr=process(dic)
			sys.stdout.write("Case #"+str(i+1)+": ")
			for a in arr:
				sys.stdout.write(str(a)+" ")
			sys.stdout.write("\n")

			




main()