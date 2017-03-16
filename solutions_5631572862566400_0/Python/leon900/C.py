import numpy as np 

# grab input
with open('C-small-attempt0.in', 'r') as f:
	content = f.readlines()

T = int(content[0]) # # of cases
data = [[val for val in line.split()] for line in content[1:]]

result = [] # list of results

#print data

for i in range(T):
	N = int(data[2*i][0])
	roster = map(int, data[2*i+1])
	
	

	count = [0]*len(roster)
	for k in range(len(roster)):
		visited = [False]*len(roster)
		j = k
		circle = [1]
		while visited[j] == False:
			visited[j] = True
			circle.append(roster[j])
			j = roster[j]-1			
		# print circle	
		
		length = len(circle)-1
		circle2 = list(set(circle))	
		count[k] = len(circle2)
		 
		if length > 1 and circle[length] == circle[length-2] and roster.count(circle[length-1]) > 1:
			count[k] += 1
				
		

	result.append(max(count)) 
	
print result

	












# write to output
with open('Csmall.txt','w+') as f:
	for count, num in enumerate(result):
		f.write("Case #%i: %i\n" % (count+1, num))	