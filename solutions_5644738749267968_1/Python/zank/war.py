import copy
import random

def is_lowest(x, items):
	for item in items:
		if item < x: return False
	return True

def is_greatest(x, items):
	for item in items:
		if item > x: return False
	return True

def min_index(items):
	min_index = 0
	for i in range(len(items)):
		if items[i] < items[min_index]:
			min_index = i
	return min_index

def max_index(items):
	max_index = 0
	for i in range(len(items)):
		if items[i] > items[max_index]:
			max_index = i
	return max_index

def calculate_war(n, weights_naomi, weights_ken):
	weights_naomi, weights_ken = copy.copy(weights_naomi), copy.copy(weights_ken)
	score = 0
	for weight_naomi in weights_naomi:
		if is_greatest(weight_naomi, weights_ken):
			score += 1
			weights_ken.pop(min_index(weights_ken))
		else:
			min_delta = None
			min_delta_index = None
			for i in range(len(weights_ken)):
				delta = weights_ken[i] - weight_naomi
				if delta > 0 and (min_delta is None or delta < min_delta):
					min_delta = delta
					min_delta_index = i

			weights_ken.pop(min_delta_index)

	return score

def calculate_deceit(n, weights_naomi, weights_ken):
	def calculate_round():
		max_weight_ken, max_weight_ken_index = None, None
		for i in range(len(weights_naomi)):
			weight = weights_ken[i]
			if max_weight_ken is None or max_weight_ken < weight:
				max_weight_ken = weight
				max_weight_ken_index = i

		for i in range(len(weights_naomi)):
			weight_naomi = weights_naomi[i]
			if is_lowest(weight_naomi, weights_ken):
				# Naomi will never win with this block. Lets waste highest Ken's block by telling him max_ken - eps weight
				weights_naomi.pop(i)
				weights_ken.pop(max_weight_ken_index)
				return 0

		for i in range(len(weights_naomi)):
			weight_naomi = weights_naomi[i]
			if is_greatest(weight_naomi, weights_ken):
				# We use this block to win and make Ken waste his highest block by lieing to him =)
				weights_naomi.pop(i)
				weights_ken.pop(max_index(weights_ken))
				return 1

		weights_naomi.pop(min_index(weights_naomi))
		weights_ken.pop(max_index(weights_ken))
		return 0

	score = 0
	while len(weights_naomi) > 0:
		score += calculate_round()
		#print(score)
		

	return score

#n = 2000
#print(calculate_deceit(n, [random.random() for i in range(n)], [random.random() for i in range(n)]))

n = int(input())
for i in range(n):
	x = int(input())
	weights_naomi = [float(a) for a in input().split(' ')]
	weights_ken = [float(a) for a in input().split(' ')]

	war_score = calculate_war(x, weights_naomi, weights_ken)
	deceit_score = calculate_deceit(x, weights_naomi, weights_ken)
	print('Case #' + str(i + 1) + ': ' + str(deceit_score) + ' ' + str(war_score))