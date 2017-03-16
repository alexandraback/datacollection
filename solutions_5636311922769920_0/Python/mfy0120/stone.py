def main1():
	inputs = open('input.in', 'r')
	outputs = open('output.out','w')
	counts = inputs.readline()
	count = counts.split()
	for i in range(int(count[0])):
		outputs.write("Case #")
		temp2 = '%d' % (i + 1)
		outputs.write(temp2)
		outputs.write(": ")
		word = inputs.readline()
		arr = word.split()
		w = 1
		for i1 in range(int(arr[1]) - 1):
			w = w * int(arr[0])
		for i1 in range(int(arr[2])):
			temp2 = '%d' % (1 + i1 * w)
			outputs.write(temp2)
			outputs.write(" ")
		outputs.write("\n")
	inputs.close()
	outputs.close()
	
main1()
