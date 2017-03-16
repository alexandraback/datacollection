# C.py

from collections import defaultdict 

def solve(num,fakes):

	global ans	

	if num == n :
		
		for k,v in r1.items():
			if v == -1 :
				return;
		for k,v in r2.items():
			if v == -1 :
				return;

		# print fakes,marked
		# print r1
		# print r2
		ans = max(ans,fakes)

		return

	i = num

	x = r1[input1[i][0]] 
	y = r2[input1[i][1]] 
	solve(num+1,fakes+1)
	marked[i] = 1
	r1[input1[i][0]] = 1
	r2[input1[i][1]] = 1
	solve(num+1,fakes)
	marked[i] = 0;
	r1[input1[i][0]] = x
	r2[input1[i][1]] = y

	# print fakes,input1[num]
	# print r1
	# print r2

	# if marked[i] == 0 :
	# 	x = r1[input1[i][0]] 
	# 	y = r2[input1[i][1]] 
	# 	solve(num+1,fakes+1)
	# 	marked[i] = 1
	# 	r1[input1[i][0]] = 1
	# 	r2[input1[i][1]] = 1
	# 	solve(num+1,fakes)
	# 	marked[i] = 0;
	# 	r1[input1[i][0]] = x
	# 	r2[input1[i][1]] = y

	# # elif r1[input1[i][0]] == -1 :
	# # 	r1[input1[i][0]] = 1;
	# # 	solve(i+1,fakes)

	# # elif r2[input1[i][1]] == -1 :
	# # 	r2[input1[i][1]] = 1
	# # 	solve(i+1,fakes)

	# else:
	# 	r1[input1[i][0]] = 1
	# 	r2[input1[i][1]] = 1
	# 	solve(i+1,fakes)

t = int(raw_input())
for _ in xrange(t):
	print 'Case #'+str(_+1)+":",
	d1 = defaultdict(int)
	d2 = defaultdict(int)
	r1 = defaultdict(int)
	r2 = defaultdict(int)
	d3 = defaultdict(list)
	d4 = defaultdict(list)
	n = int(raw_input())
	input1 = [0]*n
	marked = [0]*n
	for i in xrange(n):
		x,y = raw_input().split();
		d1[x]+=1;
		d2[y]+=1;
		r1[x] = -1
		r2[y] = -1
		d3[x].append(i);
		d4[y].append(i);
		input1[i] = [x,y]

	ans = 0;
	
	# for k,v in d1.items():		
	# 	if v == 1 :
	# 		r1[k] = 1;
	# 		marked[d3[k][0]] = 1 
	# for k,v in d2.items():		
	# 	if v == 1 :
	# 		r2[k] = 1;
	# 		marked[d4[k][0]] = 1 
	# print r1
	# print r2
	# print marked
	solve(0,0)
	print ans;


