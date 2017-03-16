import sys


def deceitful_war(naomi, ken):

	naomi_score = 0
	i = j = 0
	while i < len(naomi) and j < len(ken):
		if ken[j] < naomi[i]:
			naomi_score += 1
			j += 1
		i += 1
			
	return naomi_score

def war(naomi, ken):

	ken_score 	= 0
	i = j = 0
	while i < len(naomi) and j < len(ken):
		if naomi[i] < ken[j]:
			ken_score += 1
			i += 1
		j += 1
			
	return len(naomi)-ken_score

	
t = int(sys.stdin.readline())
for case in range(1, t+1):
	
	n = int(sys.stdin.readline())
	naomi = map(float, sys.stdin.readline().split(' '))
	naomi = sorted(naomi)

	ken = map(float, sys.stdin.readline().split(' '))
	ken = sorted(ken)

	print "Case #{0}: {2} {1}".format(case, war(naomi, ken), deceitful_war(naomi, ken))

