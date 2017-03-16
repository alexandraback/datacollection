'''
Getting the Digits
'''
import math

f = open(r"C:\Projects\CodeJam2016\1C\B\B-small-attempt4.in", "r+")
foutput = open(r"C:\Projects\CodeJam2016\1C\B\B-small-attempt4.out","w+")
data = []
for line in f:
	data.append(line.strip())
numbers = []
for i in range(int(data[0])):
	final_string = ""
	B = int(data[i+1].split()[0])
	M = int(data[i+1].split()[1])
	if M > 2**(B-2):
		final_string = "IMPOSSIBLE"
		foutput.write("Case #" + str(i+1) + ": " + final_string + "\n")
		continue
	else:
		graph = []
		for j in range(B):
			graph.append([0]*B)
		binary_string = list(bin(M))[2:]
		nodes_required = min(len(binary_string), B-1)
		for j in range(nodes_required):
			for k in range(j+1):
				graph[B-2-j][B-1-k] = 1
		if (i == 5):
			pass
		if len(binary_string) == B - 1:
			binary_string = ["1"]*(B-1)
		else:
			binary_string.append("0")		
		for j in range(len(binary_string)):
			graph[0][B-1-j] = int(binary_string[len(binary_string)-1-j]) 
		final_string = "POSSIBLE"
		foutput.write("Case #" + str(i+1) + ": " + final_string + "\n")
		for j in range(B):
			foutput.write(''.join([str(x) for x in graph[j]]) + "\n")
	
foutput.close()