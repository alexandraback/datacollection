import concurrent.futures as cf
import itertools
import re


def calc(K, L, S, keyboard, target):
	mx = 0
	tot = 0
	sum = 0
	pat = re.compile('(?={})'.format(target))
	for s in itertools.product(keyboard, repeat=S):
		tot += 1
		occ = len(pat.findall(''.join(s)))
		if occ > mx:
			mx = occ
		sum += occ
	return mx - sum / tot	


def main():
	T = int(input())
	results = []
	with cf.ProcessPoolExecutor(max_workers=8) as executor:
		for _ in range(T):
			K, L, S = [int(x) for x in input().split()]
			keyboard = input()
			target = input()
			results.append(executor.submit(calc, K, L, S, keyboard, target))
	for cs, result in enumerate(results):
		print('Case #{}: {}'.format(cs + 1, result.result()))


if __name__ == '__main__':
	main()
