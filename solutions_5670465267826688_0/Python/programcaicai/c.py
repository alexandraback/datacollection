
def convert_to_dict(table):
	return {(i+1,j+1):table[i][j] for i in range(4) for j in range(4)}
def sgn(x):
	return 1 if x>0 else -1

def op(table_dict):
	def f(a,b):
		return sgn(a)*sgn(b)*table_dict[abs(a),abs(b)]
	return f

table_mul = [[1,2,3,4],[2,-1,4,-3],[3,-4,-1,2],[4,3,-2,-1]]
dict_mul = convert_to_dict(table_mul)
op_mul = op(dict_mul)
dict_ldiv = { (abs(op_mul(i,j)),i):sgn(op_mul(i,j))*j for i in range(1,5) for j in range(1,5)}
dict_rdiv = { (abs(op_mul(i,j)),j):sgn(op_mul(i,j))*i for i in range(1,5) for j in range(1,5)}
op_ldiv = op(dict_ldiv)
op_rdiv = op(dict_rdiv)


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

def solve(s):
	arr = to_array(s)
	pre = calc_prefix(arr)
	suf = calc_prefix(arr[::-1],forward=False)[::-1]
	for i in range(len(suf)-1,0,-1):
		if suf[i]==4 and pre[i-1]==4:
			if 2 in pre[:i]:
				return True
			return False
	return False


T = int(raw_input())
for casno in range(T):
	l, k = [int(x) for x in raw_input().split()]
	s = raw_input()
	print 'Case #%d: %s' %(casno+1,'YES' if solve(s*k) else 'NO')
