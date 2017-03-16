
T = int(raw_input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case

name = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" ]
for k in range (T):
    S = raw_input()

    dic = {}
    ans = []

    for s in S:
    	if s in dic:
    		dic[s] += 1
    	else:
    		dic[s] = 1

    if 'Z' in dic:
    	x = dic['Z']

    	for s in name[0]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(0)

    if 'W' in dic:
    	x = dic['W']

    	for s in name[2]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(2)

    if 'U' in dic:
    	x = dic['U']

    	for s in name[4]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(4)

    if 'X' in dic:
    	x = dic['X']

    	for s in name[6]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(6)


    if 'G' in dic:
    	x = dic['G']

    	for s in name[8]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(8)


    if 'O' in dic:
    	x = dic['O']

    	for s in name[1]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(1)
    if 'T' in dic:
    	x = dic['T']

    	for s in name[3]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(3)
    if 'F' in dic:
    	x = dic['F']
    	for s in name[5]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(5)

    if 'S' in dic:
    	x = dic['S']

    	for s in name[7]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(7)

    if 'I' in dic:
    	x = dic['I']

    	for s in name[9]:
    		dic[s] -= x
    		if dic[s] == 0:
    			del dic[s]
    	for i in range(x):
    		ans.append(9)
    ans.sort()

    g = ''
    for i in ans:
    	g += str(i)

    print "Case #{}: {}".format(k+1, g)







