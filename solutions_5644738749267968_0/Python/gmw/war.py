import bisect

# Ken optimal strategy: plays next biggest weight than Naomi says. If he doesn't have one, then play lowest weight.
# Naomi-War strategy: while (her highest > ken's lowest): say high number, ken plays lowest, she plays next highest to Ken's lowest

def process(i, o):
	T = int(i.readline())
	for case_num in range(1, T + 1):
		N = int(i.readline())
		nams = map(float, i.readline().split())
		kens = map(float, i.readline().split())
		war = solve_war(nams[:], kens[:])
		dec = solve_deceit(nams[:], kens[:])
		o.write('Case #{}: {} {}\n'.format(case_num, dec, war))
		print 'Case #{}/{}: {} {}\n'.format(case_num, T, dec, war)
		print

def solve_war(nams, kens):
	nams.sort(reverse=True)
	kens.sort()
	points = 0

	while len(nams) > 0:
		assert len(nams) == len(kens)

		# Naomi - War
		n_play = nams.pop()

		# Ken
		pos = bisect.bisect(kens, n_play)
		if pos >= len(kens): # can't win, doesn't try
			pos = 0
		k_play = kens[pos]
		del kens[pos]

		if n_play > k_play:
			points += 1

	return points

def solve_deceit(nams, kens):
	nams.sort()
	kens.sort(reverse=True)
	points = 0

	if kens[0] == 1.0:
		del nams[0]
		del kens[0]

	while len(nams) > 0 and nams[-1] > kens[-1]:
		assert len(nams) == len(kens)

		# Naomi - Deceit
		pos = bisect.bisect(nams, kens[-1]) # find block to beat Ken's lowest
		if pos >= len(nams): # can't win this round
			del nams[-1] # she plays lowest
			del kens[0] # tricks Ken into playing highest
		else: # deceive
			del nams[pos] # she plays minimum to beat his lowest
			del kens[-1] # he plays lowest
			points += 1

	# Deceit won't work anymore, default to war
	points += solve_war(nams, kens)
	return points


def main():
	cyclename = 'D-small-0'
	with open('source\\{}.in'.format(cyclename), 'rb') as i:
		with open('source\\{}.out'.format(cyclename), 'wb') as o:
			process(i, o)
		

if __name__ == '__main__':
	main()
