import copy

T = int(input())

def rec(s1,s2,i,isEq,isInf,isSup,l1,l2):
	if i == len(s1):
		global diffMin
		global s1res
		global s2res
		myS1 = ''.join(l1)
		myS2 = ''.join(l2)
		if diffMin != -1 and abs(int(myS1) - int(myS2)) == diffMin:
			if int(myS1) < int(s1res) or (int(myS1) == int(s1res) and int(myS2) < int(s2res)):
				diffMin = abs(int(myS1) - int(myS2))
				s1res = myS1
				s2res = myS2
		elif diffMin == -1 or abs(int(myS1) - int(myS2)) < diffMin:
			diffMin = abs(int(myS1) - int(myS2))
			s1res = myS1
			s2res = myS2				
		return
	if isEq:
		if s1[i] == '?' and s2[i] == '?':
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append('0')
			l2bis.append('0')
			rec(s1,s2,i+1,isEq,isInf,isSup,l1bis,l2bis)

			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append('1')
			l2bis.append('0')
			rec(s1,s2,i+1,False,isInf,True,l1bis,l2bis)

			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append('0')
			l2bis.append('1')
			rec(s1,s2,i+1,False,True,isSup,l1bis,l2bis)
		elif s1[i] == '?':
			#Cas -1
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append(str((int(s2[i]) - 1) % 10))
			l2bis.append(s2[i])
			rec(s1,s2,i+1,False,True,isSup,l1bis,l2bis)

			#Cas egal
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append(s2[i])
			l2bis.append(s2[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1bis,l2bis)

			#Cas +1
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l1bis.append(str((int(s2[i]) + 1) % 10))
			l2bis.append(s2[i])
			rec(s1,s2,i+1,False,isInf,True,l1bis,l2bis)

		elif s2[i] == '?':
			#Cas -1
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l2bis.append(str((int(s1[i]) - 1) % 10))
			l1bis.append(s1[i])
			rec(s1,s2,i+1,False,True,isSup,l1bis,l2bis)

			#Cas egal
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l2bis.append(s1[i])
			l1bis.append(s1[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1bis,l2bis)

			#Cas +1
			l1bis = copy.deepcopy(l1)
			l2bis = copy.deepcopy(l2)
			l2bis.append(str((int(s1[i]) + 1) % 10))
			l1bis.append(s1[i])
			rec(s1,s2,i+1,False,isInf,True,l1bis,l2bis)
		else:
			l1.append(s1[i])
			l2.append(s2[i])
			if int(s1[i]) < int(s2[i]):
				isEq = False
				isInf = True

			if int(s1[i]) > int(s2[i]):
				isEq = False
				isSup = True
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)

	elif isInf:

		if s1[i] == '?' and s2[i] == '?':
			l1.append('9')
			l2.append('0')
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		elif s1[i] == '?':
			l1.append('9')
			l2.append(s2[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		elif s2[i] == '?':
			l1.append(s1[i])
			l2.append('0')
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		else:
			l1.append(s1[i])
			l2.append(s2[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)

	elif isSup:

		if s1[i] == '?' and s2[i] == '?':
			l1.append('0')
			l2.append('9')
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		elif s1[i] == '?':
			l1.append('0')
			l2.append(s2[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		elif s2[i] == '?':
			l1.append(s1[i])
			l2.append('9')
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)
		else:
			l1.append(s1[i])
			l2.append(s2[i])
			rec(s1,s2,i+1,isEq,isInf,isSup,l1,l2)

for t in range(T):
	s1, s2 = list(map(str,input().split(' ')))

	N = len(s1)

	isEq = True
	isInf = False
	isSup = False

	l1 = list()
	l2 = list()

	s1res = ''
	s2res = ''
	diffMin = -1
	
	rec(s1,s2,0,isEq,isInf,isSup,l1,l2)

	print("Case #{}: {} {}".format(t+1,s1res,s2res))

