#!/usr/bin/python3

import sys

def brute(actions, acts):
	actions = [action for action in actions if action>acts]
	if not actions:
		return acts

	a = brute(actions[:-1], acts) + 1
	b = brute(actions, next(action for action in actions if action>acts))
	return min(a,b)

def eat(armin, motes):
	if armin <2: return len(motes)

	acts = 0
	actions = []

	for i in range(len(motes)):
		while not armin > motes[i]:
			armin += (armin - 1)
			acts += 1
		armin += motes[i]
		if acts:
			actions.append(acts)
	return brute(actions, 0)

def main(infile, outfile):
	for case in range(int(next(infile))):
		armin = int(next(infile).split()[0])
		motes = sorted(int(m) for m in next(infile).split())

		actions = eat(armin, motes)

		outfile.write("Case #{0}: {1}\n".format(case+1, actions))

if __name__ == "__main__":
	with open(sys.argv[1]) as infile:
		with open(sys.argv[1][:-2] + "out", "w") as outfile:
			main(infile, outfile)
