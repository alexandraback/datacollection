def func_2(l):
	couples, used = find2circles(l)
	used = getused(l)
	sum_m = 0
	for c in couples:
		m, used = findmaxlinefor2circle(l,c,used)
		sum_m += m
		
	return sum_m

def find2circles(l):
	N = len(l)
	couples = []
	used = [False]*N
	for i in range(N):
		if l[i]>i and l[l[i]]==i:
			couples += [[i,l[i]]]
			used[i]=True
			used[l[i]]=True
			
	return couples,used
	
def findmaxlinefor2circle(l,circle,used_list):
	N = len(l)
	max_line_len1 = 0
	max_line_len2 = 0
	in_lines = [False]*N
	local_used_list = used_list
	while sum(local_used_list)!=N:
		n_list = [0]*len(l)

		for i in range(len(l)):
			if not local_used_list[i]:
				curr_node = i
				break
				
		in_line = [False]*N
		while True:
			if curr_node in circle:
				break
			elif used_list[curr_node]:
				break
				
			in_line[curr_node]=True
			curr_node = l[curr_node]

		
		local_used_list = [local_used_list[i] or in_line[i] for i in range(N)]

		if curr_node not in circle:			
			continue
			
		if curr_node==circle[0] and sum(in_line)>max_line_len1:
			max_line_len1 = sum(in_line)
		elif curr_node==circle[1] and sum(in_line)>max_line_len2:
			max_line_len2 = sum(in_line)
				
			
		in_lines = [in_lines[i] or in_line[i] for i in range(N)]
		
	used_list = [used_list[i] or in_lines[i] for i in range(N)]
	
	return 2+max_line_len1+max_line_len2, used_list


def findlinelens(l):
	N = len(l)
	# find circles
	max_num_in_circle = 0
	used_list = [False]*len(l)
	circle_list = [False]*len(l)
	line_list = [0]*N
	while sum(used_list)!=len(l):
		n_list = [0]*len(l)

		for i in range(len(l)):
			if not used_list[i]:
				curr_node = i
				break
		
		len_till_now = 0
		tmp_line_list = [0]*N
		while True:
			if n_list[curr_node]==2:
				break

			tmp_line_list[i] = len_till_now
			n_list[curr_node]+=1
			curr_node = l[curr_node]
			len_till_now += 1
		

		num_in_circle = sum(x==2 for x in n_list)
		if num_in_circle==2:
			for i in range(N):
				if n_list[i]==1:
					line_list[i]=len_till_now - tmp_line_list[i]
			
		used_list = [used_list[i] or (n_list[i]==2) or (n_list[i]==1) for i in range(len(l))]
		circle_list = [circle_list[i] or (n_list[i]==2) for i in range(len(l))]
		max_num_in_circle = max(max_num_in_circle, num_in_circle)
		
	# find lines
	used_list = circle_list
	while sum(used_list)!=N:
		n_list = [i in circle_list for i in range(N)]

		for i in range(N):
			if not used_list[i]:
				curr_node = i
				break
		
		while True:
			if n_list[curr_node]==2:
				break

			n_list[curr_node]+=1
			curr_node = l[curr_node]
			
	
def func_1(l):
	max_num_in_circle = 0
	used_list = [False]*len(l)
	while sum(used_list)!=len(l):
		n_list = [0]*len(l)

		for i in range(len(l)):
			if not used_list[i]:
				curr_node = i
				break
		
		while True:
			if n_list[curr_node]==2:
				break

			n_list[curr_node]+=1
			curr_node = l[curr_node]
		

		num_in_circle = sum(x==2 for x in n_list)
		used_list = [used_list[i] or (n_list[i]==2) or (n_list[i]==1) for i in range(len(l))]
		max_num_in_circle = max(max_num_in_circle, num_in_circle)
	return max_num_in_circle
	
def getused(l):
	max_num_in_circle = 0
	used_list = [False]*len(l)
	used_in_circle = [False]*len(l)
	while sum(used_list)!=len(l):
		n_list = [0]*len(l)

		for i in range(len(l)):
			if not used_list[i]:
				curr_node = i
				break
		
		while True:
			if n_list[curr_node]==2:
				break

			n_list[curr_node]+=1
			curr_node = l[curr_node]
		

		num_in_circle = sum(x==2 for x in n_list)
		used_list = [used_list[i] or (n_list[i]==2) or (n_list[i]==1) for i in range(len(l))]
		used_in_circle = [used_in_circle[i] or (n_list[i]==2) for i in range(len(l))]
	return used_in_circle
	

def func(l):
	v1 = func_1(l)
	v2 = func_2(l)

	return max(v1,v2)

T = int(raw_input())
for i in range(T):
	N = int(raw_input())
	l = raw_input().split()
	l = [int(x)-1 for x in l]
	print 'Case #%d: %s' % (i+1, func(l))