import itertools,re
def occurrences(text, sub):
    return len(re.findall('(?={0})'.format(re.escape(sub)), text))

def solve(K,L,S,keyboard,word):
	#Sanity Check
	for x in word:
		if not x in keyboard:
			return 0.0
	
	# keys = []
	# for w in keyboard:
	# 	if not w in keys:
	# 		keys.append(w)
	
	monkeystrings = [''.join(i) for i in itertools.product(keyboard,repeat=S)]
	outcomes = len(monkeystrings)
	maxfrequency = 0
	banannas = 0
	
	for possibleoutput in monkeystrings:
		# freq = possibleoutput.count(word)
		freq = occurrences(possibleoutput,word)
		# print freq
		maxfrequency = max(freq,maxfrequency)
		banannas = freq + banannas

	# print maxfrequency, banannas, outcomes

	return maxfrequency - float(banannas)/float(outcomes)

def dosolve(f,g):
	d = f.read().split("\n")
	n = int(d[0])

	j = 1
	for i in range(1,3*n,3):
		data = d[i].split(" ")
		K = data[0]
		L = data[1]
		S = int(data[2])
		keyboard = d[i+1]
		word = d[i+2]
		print "Case #" + str(i/3+1)
		print K,L,S,keyboard,word

		g.write ("Case #" + str(i/3+1) + ": " + str(solve(K,L,S,keyboard,word)) + "\n")

	return 0

def solve_large():
	g = open("B-large-out.txt","w")
	f = open("B-large.in","r")
	dosolve(f,g)

def solve_small():
	g = open("B-small-out-1.txt","w")
	f = open("B-small-attempt1.in","r")
	dosolve(f,g)

def solve_examples():
	g = open("B-eg-out.txt","w")
	f = open("B-eg.in","r")
	dosolve(f,g)
	
# solve_examples()
solve_small()
# solve_large