from itertools import combinations

def fonction(N, s):
	t = [set(j) for i in range(len(s)) for j in combinations(s, i+1)]
	d = {}
	for i in t:
		if sum(i) not in d:
			d[sum(i)] = i
		else:
			print(" ".join([str(k) for k in i]))
			print(" ".join([str(k) for k in d[sum(i)]]))
			break

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		args = [int(_) for _ in input().split()]
		N = args[0]
		s = set(args[1:])
		print("Case #{}:".format(t + 1))
		fonction(N, s)
