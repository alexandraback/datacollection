import sys
import os
import math

from collections import defaultdict

# in = sys.stdin
fin = open('B-large.in')
# fout = sys.stdout
fout = open('out_2', 'w')


# def count_missing(l, index):
# 	missing = 0
# 	for digit in l:
# 		missing += digit not in index
# 	return missing

# def find_missing(l, index, dim):
# 	for i, digit in enumerate(l):
# 		if digit not in index:
# 			return i

# def get_intersect(lists, row, pos, sym):
# 	same = len([col for col in lists if       (row[sym] == col[sym])])
# 	intersects = len([col for col in lists if (row[sym] == col[pos])])

# 	print '~~~', row, 'i,j:', pos, sym, 'same, int: ', same, intersects
# 	# return (same, intersects)
# 	if same == 1:
# 		return int(intersects == 1)
# 	elif same == 2:
# 		return int(intersects == 2)
# 	else:
# 		raise Exception('WTF')
# 	return False

# def solve(dim, lists):
# 	result = [0] * dim
# 	for i in range(dim):
# 		for row in lists:
# 			intersect = [get_intersect(lists, row, i, j) for j in range(dim)]
# 			print i, row, intersect
# 			if sum(intersect) == (dim - 1):
# 				print '\nALOHA:', i, intersect, intersect.index(0), row[intersect.index(0)]
# 				result[i] = row[intersect.index(0)]
# 	return result
	
			
def solve(dim, lists):
	found = {}
	target = None
	for i in range(dim):
		ok = sorted(lists, key=lambda x : x[i])	
		if len(ok) > 1 and ok[0][i] == ok[1][i]:
			found[i] = ok[:2]
			if ok:
				lists = ok[2:]
		else:
			found[i] = ok[:1]
			target = i
			if ok:
				lists = ok[1:]

	result = [0] * dim

	for i in range(dim):
		if i == target:
			result[i] = found[i][0][i]
		else:
			result[i] = found[i][0][target] if found[i][0][target] != found[target][0][i] else found[i][1][target]

	return ' '.join(map(str, result))

if __name__ == '__main__':
	count = int(fin.readline())

	for i in range(count):
		dim = int(fin.readline())
		lists = []
		for j in range(2 * dim - 1):
			lists.append(map(int, fin.readline().split()))

		result = solve(dim, lists)
		fout.write('Case #%s: %s\n' % (i + 1, result))


