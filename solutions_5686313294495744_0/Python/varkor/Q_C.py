inputData = open("Q_C_input.txt", "r")
outputData = open("Q_C_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

sub = 0
lines = []
n = 0
for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if sub > 0:
		lines.append(line)
		sub -= 1
		if sub == 0:
			fs = {}
			ss = {}
			for pair in lines:
				(f, s) = pair.split(" ")
				if f not in fs:
					fs[f] = 0
				if s not in ss:
					ss[s] = 0
				fs[f] += 1
				ss[s] += 1

			avfirst = set()
			avsec = set()
			undecided = set(lines)

			ud = list(undecided)
			for pair in ud:
				(f, s) = pair.split(" ")
				if (fs[f]) == 1 or (ss[s]) == 1:
					avfirst.add(f)
					avsec.add(s)
					undecided.remove(pair)

			faked = 0
			while len(undecided) > 0:
				ud = list(undecided)
				added = False
				for pair in ud:
					(f, s) = pair.split(" ")
					if f in avfirst and s in avsec:
						undecided.remove(pair)
						faked += 1
						added = True
				if not added:
					# Pick a new node
					pr_f = ({}, {})
					pr_s = ({}, {})
					for pair in ud:
						(f, s) = pair.split(" ")
						x = 0 if (avfirst or s in avsec) else 1
						if f not in pr_f[x]:
							pr_f[x][f] = 0
						if f not in pr_f[1-x]:
							pr_f[1-x][f] = 0
						if s not in pr_s[1-x]:
							pr_s[1-x][s] = 0
						if s not in pr_s[x]:
							pr_s[x][s] = 0
						pr_f[x][f] += 1
						pr_s[x][s] += 1
					def geh(pair):
						(f, s) = pair.split(" ")
						return (pr_f[0][f] + pr_s[0][s], pr_f[1][f] + pr_s[1][s])
					this = list(reversed(sorted(ud, key=geh)))
					(f, s) = this[0].split(" ")
					avfirst.add(f)
					avsec.add(s)
					undecided.remove(this[0])
			print(number)
			print(lines)
			case(n + 1, faked)
			n += 1
		continue
	else:
		sub = int(line)
		lines = []

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()