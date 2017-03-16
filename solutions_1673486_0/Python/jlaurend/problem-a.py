import string
import fileinput

f_in = open('A-small-attempt0.in', 'r')
f_out = open('A-small-attempt0.out', 'w')
#lines = f_in.readlines()
num_cases = f_in.readline()
prob_num = 0
while True:
	prob_num += 1
	AB = f_in.readline().strip()
	probs = f_in.readline().strip()
	if not AB:
		break
	
	AB = AB.split(' ')
	A = int(AB[0])
	B = int(AB[1])

	probs = probs.split( )

	min_exp = B + 2
	prob_product = 1.0
	i = 1
	for p_i in probs:
		prob_product *= float(p_i)
		cur_exp = prob_product * (A + B - 2 * i + 1) + (1 - prob_product) * (A + B - 2 * i + B + 2)
		if cur_exp < min_exp:
			min_exp = cur_exp
		i += 1
	
	last_case = (B - A + 1) * prob_product + (B - A + 1 + B + 2) * (1 - prob_product)
	if last_case < min_exp:
		min_exp = last_case
		

	f_out.write('Case #'+str(prob_num)+': ')
	f_out.write('%.6f' % min_exp)
	f_out.write('\n')