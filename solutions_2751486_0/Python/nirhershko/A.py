

def get_nvalue(name,n):
	#step A: find where there are consecutive consonants
	cc_locations = []
	for i in xrange(len(name) - (n-1)):
		ss = name[i:i+n]
		if not any([c in "aeiou" for c in ss]):
			cc_locations.append(i)
	
	#step B: count substrings
	count = 0
	start = 0
	while len(cc_locations):
		loc = cc_locations[0]
		
		#how many substrings start at [`start` - `loc` (inc.)]
		#	and end at [`loc+n` - `len(name)-1`]
		start_options = 1 + loc - start
		end_options = 1 + (len(name)-1) - (loc+n-1)
		count += start_options*end_options
		
		start = loc+1
		cc_locations = cc_locations[1:]
	
	return count

def read_tokens(count=None):
	line = raw_input()
	tokens = [tok.strip() for tok in line.split(" ")]
	
	if count!=None:
		assert len(tokens) == count
	
	return tokens

def main():
	T = int(read_tokens(1)[0])
	for i in range(T):
		name,n = read_tokens(2)
		n = int(n)
		num = get_nvalue(name,n)
		print "Case #%d: %d" % (i+1,num)

main()
