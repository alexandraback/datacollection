from collections import defaultdict

def solve(to):
	#print (to)
	scores = {}
	used = {}
	circles = {}

	for i in to: #all kids are keys
		dones = set()
		xs=[]
		j=i
		while not j in dones:
			xs.append(j)
			dones.add(j)
			j=to[j]

		if j==xs[-2]:
			scores[i] = len(xs)-1
			circles[i] = False
			used[i] = set(xs[:-1])
		elif j == i:
			scores[i] = len(xs)
			circles[i] = True
			used[i] = set(xs)
		else:
			scores[i] = 0
			circles[i] = False
			used[i] = set()


	bestcircle = -1
	score = 0
	comp = set()
	for (scr,i) in reversed(sorted([(scr,i) for (i,scr) in scores.items()])):
		if circles[i]==False:
			if len(comp.intersection(used[i]))==0:
				#print used[i]
				comp |= used[i]
				score += scr
		else:
			bestcircle = max([bestcircle,scr])
	#print score
	#print bestcircle
	return max([bestcircle,score])




with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it)

	for line in it:
		print ("case " + str(case))
		# -------------

		N = int(line)
		line = next(it)
		xs = [int(s) for s in line.split()]
		to={}
		for i in range(N):
			to[i+1] = xs[i]

		fout.write("Case #" + str(case) + ": " + str(solve(to)) + "\n")

		# -------------
		case += 1