import math

def isqrt(x):
	n = int(x)
	if n == 0:
		return 0;
	a, b = divmod(n.bit_length(),2)
	x = 2**(a+b)
	while True:
		y = (x+n//x)//2
		if y >= x:
			return x
		x = y

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
	return int(read_word(f), b)

def read_letters(f):
	return list(read_word(f))

def read_digits(f, b=10):
	return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
	return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
	return [int(x, b) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
	res = []
	for i in range(R):
		res.append(reader(f, *args, **kwargs))
	return res

def solve(solver, fn, out_fn=None):
	in_fn = fn + '.in'
	if out_fn is None:
		out_fn = fn + '.out'
	with open(in_fn, 'r') as fi:
		with open(out_fn, 'w') as fo:
			T = read_int(fi)
			for i in range(T):
				case = read_case(fi)
				res = solver(case)
				write_case(fo, i, res)

################################################################################

def read_case(f):
	(r,t) = read_ints(f)
	return (r,t)

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%d'%res)
    f.write('\n')

################################################################################



def solve_small(case):
    (r,t) = case
    b = 2*r - 1
    delta = b*b +8*t
    ans = (isqrt(delta)-2*r+1)/4
    print ans
    ans = math.floor(ans)
    return ans
    
solve_large = solve_small

##def solve_large(case):

solve(solve_large, 'A')
