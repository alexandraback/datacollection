import os
import math

def p_all_0_1(p, counter):
	for i in range(len(p)):
		if math.ceil(float(p[i])/float(counter[i])) > 1:
			return False
	return True
	
def determine_time(num, p):
    time = 0
    counter = [1]*len(p)
    min_time = max(p)
    while True:
	time += 1
	if p_all_0_1(p, counter):
		if time < min_time:
			min_time = time
		break
	max_pancakes = list(math.ceil(float(p[i])/float(counter[i])) for i in range(num))
	max_p = max(max_pancakes)
	i = max_pancakes.index(max_p)
	counter[i] += 1
	max_pancakes[i] = 0
	max_p_2 = max(max(max_pancakes), math.ceil(float(p[i])/float(counter[i])))
	if max_p_2 +time < min_time:
		min_time = max_p_2 + time
	if max_p_2 + time > min_time:
		break
    return int(min_time) 
            
with open('input.txt', 'r') as f:
    with open('output.txt', 'w') as g:
        line = f.readline()
        test_count = int(line)
        for i in range(test_count):
	    print i
        #for i in range(1):
            line = f.readline()
            num = int(line)
            line = f.readline()
	    p = map(float, line.split())
            g.write('Case #%s: %s\n'%(str(i+1), str(determine_time(num, p))))
