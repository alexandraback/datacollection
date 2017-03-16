
def convert_to_dict(table):
	return {(i+1,j+1):table[i][j] for i in range(4) for j in range(4)}
def sgn(x):
	return 1 if x>0 else -1
def op(table_dict):
	def f(a,b):
		return sgn(a)*sgn(b)*table_dict[abs(a),abs(b)]
	return f


def op_pow(x,n):
	s = sgn(x)
	s = s**n
	x = abs(x)
	if x==1:
		return s*x
	else:
		n1,n2 = n//2,n%2
		s *= (-1)**n1
		if n2 == 1:
			return s*x
		else:
			return s

	


table_mul = [[1,2,3,4],[2,-1,4,-3],[3,-4,-1,2],[4,3,-2,-1]]
dict_mul = convert_to_dict(table_mul)
op_mul = op(dict_mul)


def to_array(s):
	m = {'i':2,'j':3,'k':4}
	return [m[c] for c in s]

def calc_prefix(arr,forward=True):
	ret =[]
	t = 1
	for x in arr:
		if forward:
			t = op_mul(t,x)
		else:
			t = op_mul(x,t)
		ret.append(t)
	return ret

def solve_small(s):
	arr = to_array(s)
	pre = calc_prefix(arr)
	suf = calc_prefix(arr[::-1],forward=False)[::-1]
	for i in range(len(suf)-1,0,-1):
		if suf[i]==4 and pre[i-1]==4:
			if 2 in pre[:i]:
				return True
			return False
	return False



def solve(s,k):
	if len(s)*k<=10000 or k<=15:
		return solve_small(s*k)
	else:
		arr_o = to_array(s)
		pre_o = calc_prefix(arr_o)
		arr = arr_o*5
		pre = calc_prefix(arr)
		pre_mul = op_pow(pre_o[-1],k-5)

		pre_s = [op_mul(pre_mul,x) for x in pre]
		suf = calc_prefix(arr[::-1],forward=False)[::-1]
		for i in range(len(suf)-1,0,-1):
			if suf[i]==4 and pre_s[i-1]==4:
				if 2 in pre[:i]:
					return True
				return False
		return False



T = int(raw_input())
for casno in range(T):
	l, k = [int(x) for x in raw_input().split()]
	s = raw_input()
	print 'Case #%d: %s' %(casno+1,'YES' if solve(s,k) else 'NO')
