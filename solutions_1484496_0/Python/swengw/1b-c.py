f = open('C-small-attempt0.in', 'r')
ans = open('out.txt', 'w')

from itertools import *

# code borrowed from the Python docs
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def find_equal(power_set):
	for set1 in powerset(given_set):
		for set2 in powerset(given_set):
			if sum(set1) == sum(set2) and set1 != set2:
				return set1, set2

for i in range(int(f.readline().strip())):
	given_set = [int(x) for x in f.readline().strip().split()][1:]
	answer = find_equal(given_set)
	if answer == None:
		result = "Impossible"
	else:
		result = "\n"
		for item in answer[0]:
			result += str(item) + ' '
		result += "\n"
		for item in answer[1]:
			result += str(item) + ' '
	ans.write("Case #" + str(i+1) + ": " + str(result) + "\n")
	print "Case #" + str(i+1) + ": " + str(result)

f.close()
ans.close()
