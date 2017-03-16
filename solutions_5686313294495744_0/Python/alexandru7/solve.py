from collections import defaultdict

no_tests = int(input())


for test_no in range(no_tests):
	found_first = defaultdict(lambda: False)
	found_second = defaultdict(lambda: False)

	no_titles = int(input())
	count = 0

	for _ in range(no_titles):
		f,s = input().split(" ")

		if(found_first[f] and found_second[s]):
			count+= 1

		found_first[f] = True
		found_second[s] = True

	print("Case #{}: {}".format(test_no+1,count))