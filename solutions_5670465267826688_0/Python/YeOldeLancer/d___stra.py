# Google Code Jam 2015, Qualification Round
# Problem C. Dijkstra
# Lance C. Simons

def dijkstra_eval(s):
	
	if s.startswith("-"):
		d = dijkstra_digit(s[:2])
	else:
		d = dijkstra_digit(s[0])

	for c in s[1:]:
		d = d * c

	return d

class dijkstra_digit:

	mtable = {"1":{"1": "1", "i": "i", "j": "j", "k": "k"},
	          "i":{"1": "i", "i":"-1", "j": "k", "k":"-j"},
	          "j":{"1": "j", "i":"-k", "j":"-1", "k": "i"},
	          "k":{"1": "k", "i": "j", "j":"-i", "k":"-1"} }

	def __init__(self, *args):
		self.positive = True
		if type(args[0]) == type(""):
			self.positive = len(args[0]) == 1
			self.value = args[0][-1]
		elif len(args) == 1:
			self.value = args[0]
		else:
			self.positive, self.value = args

	def __neg__(self):
		return dijkstra_digit(not self.positive, self.value)
	def __mul__(self, other):
		if type(other) == type(""):
			other = dijkstra_eval(other)

		d = dijkstra_digit(self.mtable[self.value][other.value])
		if self.positive != other.positive:
			d = -d
		return d
	def __rmul__(self, other):
		return dijkstra_eval(other) * self
	def __pow__(self, exp):
		exp = exp % 4

		if self.value == "1":
			if exp == 0:
				return dijkstra_digit("1")
			elif exp == 1:
				return dijkstra_digit(self.positive, "1")
			elif exp == 2:
				return dijkstra_digit(True, "1")
			else:
				return dijkstra_digit(self.positive, "1")
		else:
			if exp == 0:
				return dijkstra_digit("1")
			elif exp == 1:
				return dijkstra_digit(self.positive, self.value)
			elif exp == 2:
				return dijkstra_digit("-1")
			else:
				return dijkstra_digit(not self.positive, self.value)

	def __eq__(self, other):
		if type(other) == type(""):
			other = dijkstra_eval(other)
		
		return self.positive == other.positive and self.value == other.value
	def __ne__(self, other):
		return not self == other

	def __str__(self):
		return ("" if self.positive else "-") + self.value
	def __repr__(self):
		return str(self)

def correctable(count, substr, maxtest=6):
	# Exit early if they are not equal
	if (dijkstra_eval(substr) ** count) != "ijk":
		return False

	strlen = len(substr)
	def at(i):
		return substr[i % strlen]

	def search_fwd(goal, *start):
		if not all(start): return None
		start = sum(start)

		i = 0
		fwd = dijkstra_digit(at(i+start))
		while fwd != goal and i < strlen * maxtest:
			i += 1
			fwd = fwd * at(i+start)

		if fwd != goal:
			return None
		return i+1

	def search_rev(goal, *end):
		if not all(end): return None
		end = sum(end)

		i = 0
		rev = dijkstra_digit(at(end-1-i))
		while rev != goal and i < strlen * maxtest:
			i += 1
			rev = at(end-1-i) * rev

		if rev != goal:
			return None
		return i+1

	def valid(*args):
		return all(args)

	def will_fit(*chars):
		chars_used = sum(chars)
		words_used = ((chars_used - 1) / strlen) + 1
		return words_used <= count

	# Forward search
	i_used_fwd = search_fwd("i")
	j_used_fwd = search_fwd("j", i_used_fwd)
	k_used_fwd = search_fwd("k", i_used_fwd, j_used_fwd)
	if valid(i_used_fwd, j_used_fwd, k_used_fwd):
		return will_fit(i_used_fwd, j_used_fwd, k_used_fwd)

	# Reverse search
	k_used_rev = search_rev("k")
	j_used_rev = search_rev("j", k_used_rev)
	i_used_rev = search_rev("i", k_used_rev, j_used_rev)
	if valid(i_used_rev, j_used_rev, k_used_rev): 
		return will_fit(i_used_rev, j_used_rev, k_used_rev)

	if valid(i_used_fwd, j_used_fwd, k_used_rev):
		return will_fit(i_used_fwd, j_used_fwd, k_used_rev)

	if valid(i_used_fwd, j_used_rev, k_used_rev):
		return will_fit(i_used_fwd, j_used_rev, k_used_rev)

	return False


def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		L,X = map(int, inf.next().strip().split())
		substr = inf.next().strip()
		outf.write("Case #%d: %s\n" % (i+1, {True:"YES", False:"NO"}[correctable(X,substr)]))

if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))
