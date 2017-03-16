from math import fabs

def type(c,j,i):
	if c[i]=='?' and j[i]=='?':
		return 0
	else:
		if c[i]!='?' and j[i]!='?':
			return 1
		else:
			if c[i]!='?' and j[i]=='?':
				return 2
			else:
				return 3

t = input()

for my in xrange(1, t+1):
	given = raw_input().split()
	c = list(given[0])
	j = list(given[1])
	n = len(c)
	flag = 0
	for i in xrange(n):
		if flag != 0 :
			break
		if flag == 0:
			mt = type(c,j,i)
			if mt == 0 :
				c[i]='0'
				j[i]='0'
			else:
				if mt == 1:
					if j[i]>c[i] :
						flag = 1
					else:
						if j[i] == c[i]:
							flag = 0
						else:
							flag = 2
				else:
					if mt==2:
						if i == n-1 or type(c,j,i+1) != 1:
							j[i] = c[i]
						else:
							diff1 = int(c[i+1])-int(j[i+1])
							diff = fabs(int(c[i+1])-int(j[i+1]))
							if diff < 5:
								j[i]=c[i]
							else:
								if diff > 5 :
									if diff1 > 0 :
										j[i] = str(int(c[i])+1)
									else:
										j[i] = str(int(c[i])-1)
								else:
									if diff1 > 0:
										j[i] = c[i]
									else:
										j[i] = str(int(c[i])-1)
						if j[i]>c[i] :
							flag = 1
						else:
							if j[i] == c[i]:
								flag = 0
							else:
								flag = 2
					else:
						if i == n-1 or type(c,j,i+1) != 1:
							c[i] = j[i]
						else:
							diff1 = int(c[i+1])-int(j[i+1])
							diff = fabs(int(c[i+1])-int(j[i+1]))
							if diff < 5:
								c[i]=j[i]
							else:
								if diff > 5 :
									if diff1 > 0 :
										c[i] = str(int(j[i])-1)
									else:
										c[i] = str(int(j[i])+1)
								else:
									if diff1 > 0:
										c[i] = str(int(j[i])-1)
									else:
										c[i] = j[i]
						if j[i]>c[i] :
							flag = 1
						else:
							if j[i] == c[i]:
								flag = 0
							else:
								flag = 2

	# print "flag " + str(flag)
	if flag == 1:
		for p,q in enumerate(c):
			if q == '?':
				c[p] = '9'
		for p,q in enumerate(j):
			if q == '?':
				j[p] = '0'
	if flag == 2:
		for p,q in enumerate(c):
			if q == '?':
				c[p] = '0'
		for p,q in enumerate(j):
			if q == '?':
				j[p] = '9'

	print 'Case #{}: {} {}'.format(my, "".join(c),"".join(j))