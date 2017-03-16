from itertools import izip_longest, chain, combinations
from decimal import Decimal
from collections import defaultdict

def cases(fh):
	return int(fh.readline())
	
def find_overlap(s):
	for letter in range(1,len(s)):
		if s[letter] == s[0]:
			if s[letter:] == s[:letter]:
				return len(s) - letter
	return 0
	
def recursively_compute_expected(S,weighted_keyboard,target, overlap):
	#monkey succeeds at typing the word
	if (S < 1):
		return 1
	P_success = reduce(lambda x,y: weighted_keyboard[y]*x, target, 1)
	P_failure = 1 - success
	return P_success*recursive_combo(S-len(target),weighted_keyboard,target, overlap) + \
			P_failure*recursively_compute_expected(S-1,weighted_keyboard,target)
	#monkey fails to type the word
	
def grouper(iterable, n, fillvalue=None):
    "Collect data into fixed-length chunks or blocks"
    # grouper('ABCDEFG', 3, 'x') --> ABC DEF Gxx
    args = [iter(iterable)] * n
    return izip_longest(fillvalue=fillvalue, *args)
	
def do_one_case_Q1(R, C, W):
	moves_until_hit = C / W
	moves_after_first_hit = W - (1 if (C % W) == 0 else 0)
	return str(R*moves_until_hit+moves_after_first_hit)

def Q1(filename):
	#pre loop
	with open(filename) as f, open(filename+"output", "w") as o:
		N = cases(f)
		index = 1
		for line in grouper(f, 1):
			R, C, W = map(int,line[0].split())
			s = do_one_case_Q1(R, C, W)
			o.write("Case #%d: %s\n" % (index, s))
			index += 1
			
def do_one_case_Q2(K, L, S, keyboard, target):
	if not set(keyboard).issuperset(set(target)):
		return "0"
	overlap = find_overlap(target)
	w = len(target)
	max = 1 + ((S-w) / (w-o))
	weighted_keyboard = defaultdict(lambda: Decimal(0))
	for letter in keyboard:
		weighted_keyboard[letter] += 1
	for letter in weighted_keyboard:
		weighted_keyboard[letter] /= len(keyboard)
	expected = recursively_compute_expected(S,weighted_keyboard,target,overlap)
	return max - expected
	
def Q2(filename):
	#pre loop
	with open(filename) as f, open(filename+"output", "w") as o:
		N = cases(f)
		index = 1
		for nums, keyboard, target in grouper(f, 3):
			K,L,S = map(int,nums[0].split())
			s = do_one_case_Q1(K, L, S, keyboard.strip(), target.strip())
			o.write("Case #%d: %s\n" % (index, s))
			index += 1	
			
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))
			

def do_one_case_Q3(C, V, denoms):
	ds = set(denoms)
	possible_values = set(filter(lambda x: x <= V, map(sum, powerset(denoms))))
	if len(possible_values) == V+1:
		return "0"
	for i in set(range(1,V+1)).difference(ds):
		possible_values = set(filter(lambda x: x <= V, map(sum, powerset(denoms+[i]))))
		if len(possible_values) == V+1:
			return "1"
	for i in set(range(1,V)).difference(ds):
		for j in set(range(i+1,V+1)).difference(ds):
			possible_values = set(filter(lambda x: x <= V, map(sum, powerset(denoms+[i,j]))))
			if len(possible_values) == V+1:
				return "2"
	for i in set(range(1,V-1)).difference(ds):
		for j in set(range(i+1,V)).difference(ds):
			for k in set(range(j+1,V+1)).difference(ds):
				possible_values = set(filter(lambda x: x <= V, map(sum, powerset(denoms+[i,j,k]))))
				if len(possible_values) == V+1:
					return "3"
	for i in set(range(1,V-2)).difference(ds):
		for j in set(range(i+1,V-1)).difference(ds):
			for k in set(range(j+1,V)).difference(ds):
				for l in set(range(k+1,V+1)).difference(ds):
					possible_values = set(filter(lambda x: x <= V, map(sum, powerset(denoms+[i,j,k,l]))))
					if len(possible_values) == V+1:
						return "4"
	return "5"
	
	
def Q3(filename):
	#pre loop
	with open(filename) as f, open(filename+"output", "w") as o:
		N = cases(f)
		index = 1
		for p, denoms in grouper(f, 2):
			C, D, V = map(int,p.split())
			denoms = map(int, denoms.split())
			s = do_one_case_Q3(C, V, denoms)
			o.write("Case #%d: %s\n" % (index, s))
			index += 1
			