def alreadyInF(i, f):

	if f.count(i) > 1:
		return True
	return False

def removeFrom(f, s, i):
	f.remove(f[i])
	s.remove(s[i])
	

def main():

	r = open('input.txt', 'r')
	w = open('out.txt', 'w')

	tc = r.readline()
	tc = int(tc)
	p = 0


	while(tc > 0):
		p += 1
		tc -= 1
		cases = r.readline()
		cases = int(cases)
		f = []
		s = []

		while(cases > 0):
			cases -= 1
			tp = r.readline()
			lst = tp.split(" ")
			f.append(lst[0])
			s.append(lst[1])


		i = len(f) - 1
		k = 0

		while (i >= 0):	
			if (alreadyInF(f[i], f)):
				if(alreadyInF(s[i], s)):
					removeFrom(f, s, i)
					k+=1
			i-=1

		case = "Case #" + str(p) + ": " + str(k) + '\n'
		w.write(case)

main()	
