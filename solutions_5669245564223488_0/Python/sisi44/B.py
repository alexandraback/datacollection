from multiprocessing import Pool
import itertools

def isValid(l):
	n = len(l)
	s = ""
	for i in range(n):
		s += l[i]
	current = s[0]
	deja = [s[0]]
	for i in s:
		if i != current:
			if i in deja:
				return False
			else:
				deja.append(i)
				current = i

	return True
def give(strings):
	res = 0
	for l in list(itertools.permutations(strings)):
		if isValid(l):
			res += 1 
	return res


def solve():
	#f = open("in.txt", 'r')
	f = open("B-small-attempt1.in.txt", 'r')
	T = int(f.readline())
	S = []
	res = [0 for i in range(T)]
	for t in range(T):
		N = int(f.readline())
		strings = f.readline().split()
		S.append(strings)
	pool = Pool()
	for ind,re in enumerate(pool.imap(give, S)):
		res[ind] = re
	for t in range(T):
		print "Case #%i:" % (t+1), (res[t]%1000000007)


solve()