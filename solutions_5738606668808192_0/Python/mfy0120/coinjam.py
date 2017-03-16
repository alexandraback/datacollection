def nextStr(str):
	a = int(str, 2) + 1;
	b = ""
	while a > 0:
		temp = (a % 2)
		temp2 = '%d' %temp
		b = temp2 + b
		a = int(a / 2)
	while len(b) < 14:
		b = "0" + b
	return b

def main1():
	inputs = open('input.in', 'r')
	outputs = open('output.out','w')
	outputs.write("Case #1:\n")
	arr = [2]
	for i in range(3, 100000):
		flag = True
		for i1 in range(len(arr)):
			if (i % arr[i1] == 0): 
				flag = False
				break
			if (arr[i1] * arr[i1] > i):
				break
		if (flag):
			arr.append(i)
	print("First Step Complete")
	
	temp1 = "00000000000000"
	allCount = 0
	threshold = 50
	while True:
		nowStr = "1" + temp1 + "1"
		arr2 = []
		totFlag = True
		for ab in range(2 , 11):
			flag = False
			temp3 = int(nowStr, ab)
			for i1 in range(len(arr)):
				if (temp3 % arr[i1] == 0):
					arr2.append(arr[i1])
					flag = True
					break
				if (arr[i1] * arr[i1] > temp3):
					break
			if (flag == False):
				totFlag = False
				break
		if (totFlag):
			allCount = allCount + 1
			print(nowStr, end='')
			outputs.write(nowStr)
			for i2 in range(9):
				outputs.write(" ")
				temp2 = '%d' %arr2[i2]
				outputs.write(temp2)
			outputs.write("\n")
			if (allCount == threshold):
				break
		temp1 = nextStr(temp1)
	inputs.close()
	outputs.close()
main1()
