filename = "A_in.txt"

f = open("A_in.txt")
out = open("A_out.txt", "w")

import math

num_cases = int(f.readline())

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

for case_num in xrange(num_cases):

	data = [int(a) for a in f.readline().strip().split("/")]
	
	numer = data[0]
	denom = data[1]
	
	
	gcdenom = gcd(numer,denom)
	while gcdenom != 1:
		numer /= gcdenom
		denom /= gcdenom
		
		gcdenom = gcd(numer,denom)
	
	# Test to see if possible
	tester = denom
	move_to_next = False
	
	print numer,denom
	
	if denom == 1:
		print("Case #{0}: {1}".format(case_num + 1, "impossible"))
		out.write("Case #{0}: {1}\n".format(case_num + 1, "impossible"))	
		continue
		
	jump_to_end = False
	while tester != 1:
		# print answer, tester
		if tester % 2 != 0:
			# Impossible
			print("Case #{0}: {1}".format(case_num + 1, "impossible"))
			out.write("Case #{0}: {1}\n".format(case_num + 1, "impossible"))
			jump_to_end = True
			break
		tester /= 2
		
	if jump_to_end:
		continue
	
	
	frac = 1.0/2
	
	answer = 1
	while answer <= 41:
		if (numer*1.0/denom) >= frac:
			break
		frac /= 2
		answer += 1
		
	print("Case #{0}: {1}".format(case_num + 1, answer))
	out.write("Case #{0}: {1}\n".format(case_num + 1, answer))
		

f.close()
out.close()