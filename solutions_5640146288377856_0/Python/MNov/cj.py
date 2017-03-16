from itertools import izip_longest

def cases(fh):
	return int(fh.readline())
	
def same_parity(a,b):
	return a % 2 == b % 2
	
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