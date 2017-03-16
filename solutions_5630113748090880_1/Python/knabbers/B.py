from collections import defaultdict

with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it)

	for line in it:
		print ("case " + str(case))
		# -------------

		N = int(line)
		h={}
		for i in range(2*N-1):
			line = next(it)
			xs = [int(s) for s in line.split()]
			#print (xs)
			for x in xs:
				if not x in h:
					h[x] = 1
				else:
					h[x] += 1

		r=[]
		for k in h:
			if h[k]%2==1:
				r.append(k)

		res = ' '.join(str(x) for x in sorted(r))

		fout.write("Case #" + str(case) + ": " + str(res) + "\n")

		# -------------
		case += 1