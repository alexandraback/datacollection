import copy
import itertools
from hopcroftkarp import HopcroftKarp


def solve(topics):
	n = len(topics)
	graph = {}
	for t in topics:
		if t[0] not in graph.keys():
			graph[t[0]] = set()
		graph[t[0]].add(t[1])
	# print(graph)
	n_matched = len(HopcroftKarp(graph).maximum_matching()) // 2
	# print(HopcroftKarp(graph).maximum_matching())
	points = len(set(t[0] for t in topics)) + len(set(t[1] for t in topics))
	print(n - (points - n_matched))


def main():
	num_of_test = int(input())

	for test_id in range(1, num_of_test + 1):
		num = int(input())
		topics = []
		for i in range(num):
			ttt = input().split()
			ttt[0] += "_"
			topics.append(ttt)
		print("Case #" + str(test_id) + ": ", end="")
		solve(topics)

if __name__ == "__main__":
	main()
