import lib
from sets import Set


@lib.wrapper
def solution(input, output):
	vowels = ['a', 'e','i','o','u']
	T = input.int()
	for case in xrange(T):
		print 'case %d' % case
		N = input.int()
		attacks = {}
		for i in xrange(N):
			d, n, w, e ,s, delta_d, delta_p, delta_s = input.int_tuple()
			for _ in xrange(n):
				if not d in attacks:
					attacks[d] = []
				attacks[d].append((w,e,s))
				w += delta_p
				e += delta_p
				s += delta_s
				d += delta_d
		wall = {}
		successes = 0
		for day in sorted(attacks.keys()):
			attacks_today = attacks[day]
			for w,e,s in attacks_today:
				for i in xrange(w,e):
					if (not i in wall) or s>wall[i]:
						successes +=1
						break
			for w,e,s in attacks_today:
				for i in xrange(w,e):
					if not i in wall:
						wall[i] = s 
					else:
						wall[i] = max(wall[i],s)
		output.result(case+1, successes)
if __name__ == '__main__':
	solution()
