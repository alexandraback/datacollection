def calc_ranges(base, complexity):
	r = [0]
	pr = 1
	for x in xrange(complexity):
		pr *= base
		r.append(pr)
	return r

# def get_position(ranges, check_stack):
# 	pos = 0
# 	for i in check_stack:
# 		pos += ranges[i-1]*(i-1)
# 	return pos

def get_position(ranges,count, check_stack):
	if count == 1:
		#print "Last: %d"%check_stack[0]
		return check_stack[0]
	shift = ranges[count-1]*(check_stack[count-1]-1)
	deeper_val = get_position(ranges,count-1,check_stack)
	#print (ranges,check_stack, count)
	#print "shift %d\tval %d"%(shift,deeper_val)
	return shift+deeper_val


def check_next(base, complexity, last_checked):
	to_check = last_checked+1
	check_stack = []
	for x in xrange(0,complexity):
		check_stack.append(to_check)
		to_check+=1
		if to_check>base:
			break
	return check_stack, to_check-1

out_strings = []
T = input()
for itttt in xrange(T):
	base, complexity, students = [int(x) for x in raw_input().split()]
	last_checked = 0
	ranges = calc_ranges(base, complexity)
	s = 0
	positions = []
	while s<students and last_checked<base:
		check_stack, last_checked = check_next(base, complexity,last_checked)
		#p = get_position(ranges, check_stack)
		p = get_position(ranges,len(check_stack),check_stack)
		s+=1
		positions.append(p)
	out = "IMPOSSIBLE" if last_checked!=base else " ".join([str(x) for x in positions])
	out_strings.append("Case #%d: %s"%(itttt+1,out))
print "\n".join(out_strings)

def out_file():
	f = open('output.txt','w')
	f.write('\n'.join(out_strings))
	f.close()

#out_file()