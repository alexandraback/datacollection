#!/usr/bin/env python

from __future__ import division
import math

""" 
The total points for a Googler is the sum of the three scores in that
Googler's triplet of scores. The best result for a Googler is the maximum of
the three scores in that Googler's triplet of scores. Given the total points
for each Googler, as well as the number of surprising triplets of scores, what
is the maximum number of Googlers that could have had a best result of at
least p? 

notes.md

         N          S 

mod 0    x/3        x/3 + 1
mod 1    ceil(x/3)  ceil(x/3)
mod 2    ceil(x/3)  ceil(x/3) + 1

"""

import pprint

if __name__ == '__main__':
	cases = []
	with open('B-large.in') as handle:

		# bookkeeping
		lines = handle.readlines()
		for line in lines[1:]:
			numbers = map(int, line.strip().split(' '))
			case = {}
			case['surprising'] = numbers[1]
			case['p'] = numbers[2]
			case['totals'] = numbers[3:]
			cases.append(case)

		# pprint.pprint(cases)

		for case_id, case in enumerate(cases, start=1):
			p = case['p']
			# store the max scores a judge could have given
			max_scores = []
			max_scores_w_surprise = []

			for total in case['totals']:
				# 0 = 0 + 0 + 0
				if total == 0:
					max_score = max_score_w_surpise = 0
				# see notes
				elif total % 3 == 0:
					max_score = (total / 3)
					max_score_w_surpise = (total / 3) + 1
				elif total % 3 == 1:
					max_score = math.ceil(total / 3)
					max_score_w_surpise = math.ceil(total / 3)
				elif total % 3 == 2:
					max_score = math.ceil(total / 3)									
					max_score_w_surpise = math.ceil(total / 3) + 1
				max_scores.append(max_score)
				max_scores_w_surprise.append(max_score_w_surpise)

			counter = 0
			# passing without surprise
			for i, max_score in enumerate(max_scores):
				if max_score >= p:
					counter += 1
					# eliminate from possible surprise
					max_scores_w_surprise[i] = None

			# print(max_scores_w_surprise)

			# possibly passing with surprise
			surprises = case['surprising']
			for max_score in max_scores_w_surprise:
				if surprises > 0 and max_score >= p:
					counter += 1
					surprises -= 1

			# print(counter)
			print('Case #%s: %s' % (case_id, counter))

