import os

input = "test.in"
#input = "a-small.in";
#input = "a-large.in";
input = "A-large.in"

output = input.replace(".in", ".out")

in_f = open(input, "r")

def get_line():
	return in_f.readline()[:-1]
	
def get_int():
	return int(get_line())

def get_sep():
	return get_line().split(" ")
	
def get_sep_int():
	return [int(i) for i in get_sep()]	

def get_moves_from_here(size, motes):
	if size == 1:
		return len(motes)
	while(1):
		if motes == []:
			return 0
		if (size > motes[0]):
			size += motes[0]
			motes = motes[1:]
			continue
		return min(len(motes), get_moves_from_here(size + size - 1, motes) + 1)

def get_solution_str(begin, motes):
	motes = sorted(motes)
	#print begin, motes
	return str(get_moves_from_here(begin, motes))

num_cases = get_int()
out = open(output, "w")

for cur_case in xrange(1, num_cases + 1):
	print cur_case
	begin, other = get_sep_int();
	motes = get_sep_int();
	assert(len(motes) == other)
		
	sol = get_solution_str(begin, motes)
	
	out.write("Case #%d: %s\n" %(cur_case, sol))