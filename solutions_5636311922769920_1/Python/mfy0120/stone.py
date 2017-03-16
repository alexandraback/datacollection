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
		if (int(arr[0]) - int(arr[1]) >= int(arr[2])):
			outputs.write("IMPOSSIBLE\n");
			continue;
		for i1 in range(1, int(arr[1]) + 1):
			w = (w - 1) * int(arr[0]) + min(i1, int(arr[0]))
		for i1 in range(int(arr[2])):
			temp2 = '%d' % (w)
			outputs.write(temp2)
			outputs.write(" ")
			w = w + 1
		outputs.write("\n")
	inputs.close()
	outputs.close()
	
main1()
