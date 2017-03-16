
from math import factorial
from itertools import permutations

def nchoosek(n, k):
	return factorial(n)//(factorial(n-k)*factorial(k))

def find_starting(cars, c):
	pass

def combine_equals(cars):
	cnt = 1
	i = 0
	N = len(cars)
	ncars = []
	while i < N:
		ncars.append(cars[i])
		j = i+1
		cset = set(cars[i])
		while j < N:
			ncset = set(cars[j])
			if ncset != cset:
				cnt *= factorial(j-i)
				break
			else:
				ncars[-1] = ncars[-1]+cars[j]
			j += 1

		i = j
	return ncars, cnt

def combine_required(cars):
	i = 0
	N = len(cars)
	while i<N:
		if cars[i][0]==cars[i][-1]:
			for j in xrange(N):
				if i==j:
					continue
				if cars[j][0]==cars[i][0]:
					cars[i] = cars[i]+cars[j]
					cars.pop(j)
					N -= 1
					i = -1
					break
				elif cars[j][-1]==cars[i][0]:
					cars[j] = cars[j]+cars[i]
					cars.pop(i)
					N -= 1
					i = -1
					break
		i += 1

	i=0
	while i < N:
		for j in xrange(N):
			if i==j:
				continue
			if cars[i][-1]==cars[j][0]:
				cars[i] = cars[i]+cars[j]
				N -= 1
				cars.pop(j)
				i = -1
				break
		i+=1
	return cars

def solve(cars):
	cars.sort()
	cars,cnt = combine_equals(cars)
	cars.sort()
	#cnt = cnt%1000000007
	cars = combine_required(cars)
	cnt = cnt*factorial(len(cars))%1000000007
	train = reduce(lambda a,b: a+b, cars, "")
	letters = set([])
	lc = ""
	for c in train:
		if lc != c and c in letters:
			return 0
		lc = c
		letters.add(c)
	return cnt

T = int(raw_input())
for t in xrange(1, T+1):
	N = int(raw_input())
	cars = raw_input().split()
	print "Case #{}: {}".format(t, solve(cars))
