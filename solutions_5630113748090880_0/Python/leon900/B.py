import numpy as np 
from collections import Counter

# grab input
with open('B-small-attempt0.in', 'r') as f:
	content = f.readlines()

T = int(content[0]) # # of cases
data = [[val for val in line.split()] for line in content[1:]]

result = [] # list of results

M=0
for i in range(T):
	N = int(data[M][0])	
	row = []
	for m in range(2*N-1):
		row = row + data[M+m+1] 
	print N	
	cnt = Counter(row)
	ans = []
	for key, val in cnt.iteritems():
		if val%2 == 1:
			ans.append(key)
	
	ans2 = map(int, ans)
	ans2.sort()
	result.append(ans2)
	M += 2*N; 














#write to output
with open('Bsmall.txt','w+') as f:
	for count, num in enumerate(result):
		#f.write("Case #%i: %d\n" % (count+1, item for item in result[count]))	
		f.write("Case #%i: " % (count+1))
		for i in result[count]:
			f.write(str(i) + " ")
		f.write("\n")