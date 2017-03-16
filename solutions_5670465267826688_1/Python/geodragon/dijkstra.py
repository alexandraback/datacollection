import os
import math

I = 2
J = 3
K = 4
table = [[1, I, J, K], [I, -1, K, -J], [J, -K, -1, I], [K, J, -I, -1]]
str_map = {"i" : I, "j": J, 1: 1, "k": K}

def multiply(q1, q2):
	sign = 1
	if q1 < 0:
		sign *= -1
	if q2 < 0:
		sign *= -1
	q1, q2 = abs(q1), abs(q2)
	return sign*table[q1-1][q2-1]

def raise_to(q1, power):
	num = power%4
	if num == 0 or power == 0:
		return 1
	if num == 1:
		return q1
	if num == 2:
		return multiply(q1, q1)
	if num == 3:
		return multiply(q1, multiply(q1, q1))

def determine_possible(X, string):
	# product of the string
	prod = 1
	for char in string:
		prod = multiply(prod, str_map[char])
	if raise_to(prod, X) != -1:
		return "NO"
	prod2 = prod
	poss = [1]
	if X > 1:
		poss.append(prod)
	if X > 2:
		poss.append(-1)
	if X > 3:
		poss.append(-1*prod)
	# find the i
	prod = 1
	index = 0
	index_ideal = 0
	found_with = None 
	found = None
	for char in string:
		prod = multiply(prod, str_map[char])
	#	print prod
	#	print found
	#	print found_with
		for possibility in poss:
			if multiply(possibility, prod) == I:
				if found_with == None or poss.index(found_with) > poss.index(possibility):
					found = True
					found_with = possibility
					index_ideal = index
		index += 1
			
	# if not found return
	if found == None:
		return "NO"
	index = poss.index(found_with)*len(string)+index_ideal
	#index = index_ideal
	# find the k
	gone = math.ceil(float(index+1)/float(len(string)))
	#if (index+1)%len(string) == 0:
	
	index = index_ideal
	#	gone += 1
	X = X-gone
	poss = [1]
	if X > 0:
		poss.append(prod)
	if X > 1:
		poss.append(-1)
	if X > 2:
		poss.append(-1*prod)
	#start = math.ceil(float(index+1)/float(len(string)))*len(string)
	start = len(string)-1
	prod = 1
	flag = True
	while start >= 0:
		if X == 0 and start <= index:
			start = -1
			break
		if start <= index and X-1<3 and X> 0 and flag:
			flag = False
			poss.pop()
		found = False
		prod = multiply(str_map[string[int(start)]], prod)
		for possibility in poss:
			if multiply(prod, possibility) == K:
				found = True
		if found:
			break
		start -= 1
	if start == -1:
		return "NO"
	return "YES"
            
with open('input.txt', 'r') as f:
    with open('output.txt', 'w') as g:
        line = f.readline()
        test_count = int(line)
        for i in range(test_count):
	    print i
        #for i in range(1):
            line = f.readline()
            X = int(line.split()[1])
            line = f.readline()
	    string = line.strip()
	    #if i != 51:
	    #	    continue
            g.write('Case #%s: %s\n'%(str(i+1), str(determine_possible(X, string))))
