
def funcs(arrs, bent):
	arrs = list(arrs)
	bent = list(bent)
	nexts = len(arrs)
	for i in xrange(nexts):
		if i == 0:
			if arrs[i] == '?' and bent[i] == '?':
				if len(arrs) == 1:
					arrs[i] = 0
					bent[i] = 0
				elif arrs[i+1] == '?' or bent[i+1] == '?':
					arrs[i] = 0
					bent[i] = 0
				else:
					if abs(int(arrs[i+1])-int(bent[i+1])) > 5:
						if int(arrs[i+1]) > int(bent[i+1]):
							bent[i] = 1
							arrs[i] = 0
						else:
							arrs[i] = 1
							bent[i] = 0
					else:
						arrs[i] = 0
						bent[i] = 0
			elif arrs[i] == '?':
				if len(arrs) == 1:
					arrs[i] = bent[i]
				else:
					if arrs[i+1] == '?' or bent[i+1] == '?' or arrs[i+1] == bent[i+1]:
						arrs[i] = bent[i]
					elif int(bent[i+1]) > int(arrs[i+1]):
						if int(bent[i+1])-int(arrs[i+1]) > 5:
							arrs[i] = int(bent[i])+1
						else:
							arrs[i] = bent[i]
					else:
						if int(arrs[i+1])-int(bent[i+1]) < 5:
							arrs[i] = bent[i]
						else:
							arrs[i] = int(bent[i]) - 1
			elif bent[i] == '?':
				if len(bent) == 1:
					bent[i] = arrs[i]
				else:
					if arrs[i+1] == '?' or bent[i+1] == '?' or arrs[i+1] == bent[i+1]:
						bent[i] = arrs[i]
					elif int(arrs[i+1]) > int(bent[i+1]):
						if int(arrs[i+1])-int(bent[i+1]) > 5:
							bent[i] = int(arrs[i])+1
						else:
							bent[i] = arrs[i]
					else:
						if int(bent[i+1])-int(arrs[i+1]) < 5:
							bent[i] = arrs[i]
						else:
							bent[i] = int(arrs[i]) - 1


		else:
			if arrs[i] == '?':
				if arrs[:i] == bent[:i]:
					if bent[i] == '?':
						if i == nexts-1:
							arrs[i] = 0
						else:
							if arrs[i+1] == '?' or bent[i+1] == '?' or arrs[i+1]  == bent[i+1]:
								arrs[i] = 0
							else:
								if int(bent[i+1]) - int(arrs[i+1]) > 5:
									arrs[i] = 1
									bent[i] = 0
								else:
									arrs[i] = 0
									bent[i] = 0
					else:
						if i == nexts-1:
							arrs[i] = bent[i]
						else:
							if arrs[i+1] == '?' or bent[i+1] == '?' or arrs[i+1]  == bent[i+1]:
								arrs[i] = bent[i]
							else:
								if int(arrs[i+1]) > int(bent[i+1]) and int(arrs[i+1])-int(bent[i+1])>=5:
									arrs[i] = int(bent[i])-1
								elif int(bent[i+1])>int(arrs[i+1]) and int(bent[i+1])-int(arrs[i+1]) >= 5:
									arrs[i] = int(bent[i])+1
								else:
									arrs[i] = bent[i]


				else:
					if int(''.join([str(s) for s in arrs[:i]])) > int(''.join([str(s) for s in bent[:i]])):
						arrs[i] = 0
					else:
						arrs[i] = 9
			if bent[i] == '?':
				if bent[:i] == arrs[:i]:
					if arrs[i] == '?':
						if i == nexts-1:
							bent[i] = 0
						else:
							if bent[i+1] == '?' or arrs[i+1] == '?' or arrs[i+1]  == bent[i+1]:
								bent[i] = 0
							else:
								if int(arrs[i+1]) - int(bent[i+1]) > 5:
									bent[i] = 1
									arrs[i] = 0
								else:
									bent[i] = 0
									arrs[i] = 0
					else:
						if i == nexts-1:
							bent[i] = arrs[i]
						else:
							if arrs[i+1] == '?' or bent[i+1] == '?' or arrs[i+1]  == bent[i+1]:
								bent[i] = arrs[i]
							else:
								if int(bent[i+1]) > int(arrs[i+1]) and int(bent[i+1])-int(arrs[i+1])>=5:
									bent[i] = int(arrs[i])-1
								elif int(arrs[i+1])>int(bent[i+1]) and int(arrs[i+1])-int(bent[i+1]) >= 5:
									bent[i] = int(arrs[i])+1
								else:
									bent[i] = arrs[i]


				else:
					if int(''.join([str(s) for s in bent[:i]])) > int(''.join([str(s) for s in arrs[:i]])):
						bent[i] = 0
					else:
						bent[i] = 9
	x = ''.join([str(s) for s in arrs])
	y = ''.join([str(s) for s in bent])
	return (x,y)

inputs = []
for _ in xrange(input()):
	inputs.append(raw_input())

for i in xrange(len(inputs)):
	st = inputs[i].split()
	s1 = st[0]
	s2 = st[1]
	ans = funcs(s1, s2)
	print "Case #%d: %s %s"%(i+1, ans[0], ans[1])