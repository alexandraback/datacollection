import numpy as np 

# grab input
with open('A-small-attempt0.in', 'r') as f:
	content = f.readlines()

T = int(content[0]) # # of cases
data = [[val for val in line.split()] for line in content[1:]]

result = [] # list of results

for word in data:
	ans = word[0][0]
	for i in range(1, len(word[0])):
		c = word[0][i]
		if c >= ans[0][0]:
			ans = c + ans
		else:
			ans = ans + c
	result.append(ans)













# write to output
with open('Asmall.txt','w+') as f:
	for count, num in enumerate(result):
		f.write("Case #%i: %s\n" % (count+1, num))	