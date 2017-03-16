from collections import defaultdict

def f(s):
	if len(s) <= 1:
		return s

	mx = max(s)
	r=[]
	pre=[]
	post=[]
	rdone=False
	for c in s:	
		if c>=mx or rdone:
			rdone = True
			if c==mx:
				pre.append(c)
			else:
				post.append(c)
		else:			
			r.append(c)			

	return pre + f(r) + post

		


with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it)

	for line in it:
		print ("case " + str(case))
		# -------------

		s = list(str(line.strip()))
		#print ("line = " + str(s))

		fout.write("Case #" + str(case) + ": " + ''.join(f(s)) + "\n")

		# -------------
		case += 1