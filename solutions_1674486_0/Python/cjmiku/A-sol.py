#!/usr/bin/env python
# coding: utf-8

import string
import pprint

def paths(graph, start, end):
    todo = [[start, [start]]]
    while 0 < len(todo):
        (node, path) = todo.pop(0)
        for next_node in graph[node]:
            if next_node in path:
                continue
            elif next_node == end:
                yield path + [next_node]
            else:
                todo.append([next_node, path + [next_node]])


if __name__ == '__main__':
	with open('A-small-attempt1.in') as handle:
		lines = map(string.strip, handle.readlines())

	cases = {}
	# the cases
	start, end = True, None
	case_id = 0
	for i, line in enumerate(lines[1:]):

		if i == end:
			start = True

		if start == True:
			case_id += 1
			cases[case_id] = {}
			j, start = 1, False
			number_of_classes = map(int, line.split())[0]
			end = i + number_of_classes + 1
			# print('new case, ends: %s' % end)
		else:
			# case[j] = map(int, line.split())
			cases[case_id][j] = map(int, line.split())[1:]
			# print(j, line)
			j += 1

	# pprint.pprint(cases)
	abort = False
	has_diamond = 'No'
	for case_id, case in cases.items():
		
		abort, has_diamond = False, 'No'
		
		for start in case.keys():
			if abort == True:
				break

			for end in case.keys():
				if abort == True:
					break

				# print(start, end, [ p for p in paths(case, start, end) ])
				if len([ p for p in paths(case, start, end) ]) > 1:
					has_diamond = 'Yes'
					abort = True
						
				# print(start, end, len([ p for p in paths(case, start, end) ]))
				# if [ p for p in paths(case, start, end) ]
		print('Case #%s: %s' % (case_id, has_diamond))
