import sys
from collections import defaultdict as ddict
sys.setrecursionlimit(100000)
def main(f,o):
	t = int(f.readline())
	for t2 in range(t):
		n = int(f.readline())
# 		print(f.readline())
		li = [int(i) for i in f.readline().split(' ')]
		chains = ddict(list)
		max_cycle = 0
		for i,j in enumerate(li):
			curr_chain = [i+1]
			next_k = li[i]
			while next_k not in curr_chain:
				curr_chain.append(next_k)
				next_k = li[next_k-1]

			print(curr_chain)
			if next_k == curr_chain[0] and len(curr_chain) > max_cycle:
				max_cycle = len(curr_chain)

			if next_k == curr_chain[-2]:
				couple_final = (curr_chain[-2],curr_chain[-1])
				if len(chains[couple_final]) < len(curr_chain):
					chains[couple_final] = curr_chain

		kids = set()
		for chain in chains.values():
			for i in chain:
				kids.add(i)

		max_kids = max(len(kids),max_cycle)

		o.write('Case #%d: %d\n'%(t2+1,max_kids))

with open('input') as f, open('output','w') as o:
	main(f,o)
