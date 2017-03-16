prod_table = {
	('1','1'): '1', ('1','i'): 'i', ('1','j'): 'j', ('1','k'): 'k',
	('i','1'): 'i', ('i','i'): '-1', ('i','j'): 'k', ('i','k'): '-j',
	('j','1'): 'j', ('j','i'): '-k', ('j','j'): '-1', ('j','k'): 'i',
	('k','1'): 'k', ('k','i'): 'j', ('k','j'): '-i', ('k','k'): '-1',
}

power_table = {
	('i', 1): 'i', ('i', 2): '-1', ('i', 3): '-i', ('i', 0): '1',
	('j', 1): 'j', ('j', 2): '-1', ('j', 3): '-j', ('j', 0): '1',
	('k', 1): 'k', ('k', 2): '-1', ('k', 3): '-k', ('k', 0): '1',
}

def prod(op1, op2):
	if len(op1) == 2 and len(op2) == 2:
		result = prod_table[(op1[1], op2[1])]
	elif len(op1) == 2:
		result = '-' + prod_table[(op1[1], op2)]
	elif len(op2) == 2:
		result = '-' + prod_table[(op1, op2[1])]
	else:
		result = prod_table[(op1, op2)]
	if len(result) == 3:
		result = result[2]
	return result

def evaluate(string):
	if len(string) == 1:
		return string
	else:
		result = string[0]
		for idx, ch in enumerate(string):
			if idx > 0:
				result = prod(result, ch)
		return result

def power(ch, n):
	if len(ch) == 2:
		if n % 2 == 0:
			result = power(ch[1], n)
		else:
			result = '-' + power(ch[1], n)
	else:
		if ch == '1':
			result = ch
		else:
			result = power_table[(ch, n % 4)]
	if len(result) == 3:
		result = result[2]
	return result

def first_i(string):
	accu = '1'
	for idx, ch in enumerate(string):
		accu = prod(accu, ch)
		if accu == 'i':
			return idx
	return None

def last_k(string):
	accu = '1'
	seq = [tup for tup in enumerate(string)]
	for idx, ch in reversed(seq):
		accu = prod(ch, accu)
		if accu == 'k':
			return idx
	return None

def can_decompose(string, repeat, length):
	if length * repeat < 3:
		return "NO"
	total_prod = power(evaluate(string), repeat)
	if total_prod != evaluate('ijk'):
		return "NO"
	repeated_string = string * 4
	if repeat <= 4:
		repeated_string = string * repeat
	i_pos = first_i(repeated_string)
	k_pos = last_k(repeated_string)
	if i_pos is None or k_pos is None:
		return "NO"
	if repeat <= 4:
		if i_pos + 1 < k_pos:
			# print repeated_string[:(i_pos+1)], repeated_string[k_pos:]
			return "YES"
		else:
			return "NO"
	else:
		new_k_pos = k_pos + (repeat - 4) * length
		if i_pos + 1 < new_k_pos:
			# print repeated_string[:(i_pos+1)], repeated_string[k_pos:]
			return "YES"
		else:
			return "NO"

T = int(raw_input())
for test in xrange(T):
	L, X = [int(i) for i in raw_input().split(" ")]
	S = raw_input()
	result = can_decompose(S, X, L)
	print "Case #%d: %s" % (test + 1, result)
