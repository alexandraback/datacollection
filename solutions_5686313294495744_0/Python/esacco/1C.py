from collections import Counter


def solve (talks):
	f_names = Counter(t[0] for t in talks)
	s_name = Counter(t[1] for t in talks)
	tmp_f_name = set()
	tmp_s_name = set()
	cheat = 0
	for t in [t for t in talks if f_names[t[0]] == 1 or s_name[t[1]] == 1]:
		tmp_f_name.add(t[0])
		tmp_s_name.add(t[1])
	for t in [t for t in talks if f_names[t[0]] !=1 and s_name[t[1]] != 1]:
		if t[0] not in tmp_f_name or t[1] not in tmp_s_name:
			tmp_f_name.add(t[0])
			tmp_s_name.add(t[1])
		else:
			cheat += 1
	return cheat


if __name__ == "__main__":
	testcases = input()

	for caseNr in xrange(1, testcases+1):
		number_of_talk = input()
		talks = []
		for t in xrange(number_of_talk):
			talks.append(raw_input().split())		 
		print("Case #%i: %s" % (caseNr, solve(talks)))
		



