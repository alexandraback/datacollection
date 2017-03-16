from cjlib.input import *
from cjlib.runner import TaskRunner, DummyRunner, MPQRunner
import logging

logging.basicConfig(level=logging.DEBUG)

def process(case):
	case[1] = int(case[1])
	ban = "aeiou"
	combo = []
	ccombo = []
	for k,v in enumerate(case[0]):
		if v in ban:
			if len(ccombo) >= case[1]:
				combo.append(ccombo)
			ccombo = []
		else:
			ccombo += [k]
	if len(ccombo) >= case[1]:
		combo.append(ccombo)
	out = 0
	for start in range(len(case[0])):
		for end in range(start + case[1], len(case[0])+1):
			#print start,end, case[0][start:end]
			for c in combo:
				matched = 0
				for r in range(start, end):
					if r in c:
						#print r,c,case[0][r]
						matched += 1
				if matched >= case[1]:
					#print c, matched, case[0][start:end]
					out += 1
					break

	return out

get("""4
quartz 3
straight 3
gcj 2
tsetse 2""")

#r = TaskRunner(process, MPQRunner, processCnt=8)
r = TaskRunner(process, DummyRunner)

while neof():
	r.add(line().split(" "))

r.run(True)