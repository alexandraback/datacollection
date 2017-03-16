import copy
import itertools


def solve(topics):
	n = len(topics)
	ans = 0
	for t in range(2**n):
		real = []
		fake = []
		for i in range(n):
			if (t >> i) % 2 > 0:
				real.append(topics[i])
			else:
				fake.append(topics[i])
		real_first = set(t[0] for t in real)
		real_second = set(t[1] for t in real)
		valid = True
		for top in fake:
			if top[0] in real_first and top[1] in real_second:
				pass
			else:
				valid = False
		if valid:
			ans = max(ans, len(fake))
	print(ans)


def main():
	num_of_test = int(input())

	for test_id in range(1, num_of_test + 1):
		num = int(input())
		topics = []
		for i in range(num):
			topics.append(input().split())
		print("Case #" + str(test_id) + ": ", end="")
		solve(topics)

if __name__ == "__main__":
	main()
