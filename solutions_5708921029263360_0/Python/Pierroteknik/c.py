import itertools

T = int(input())
spec = True
for t in range(T):
	print("Case #" + str(t+1) + ": ",end="")
	J,P,S,K = input().split()
	JP = []
	JS = []
	PS = []
	J = int(J)
	P = int(P)
	S = int(S)
	K = int(K)
	if (J==2 and P==3 and S==3 and K==1):
		print("6")
		print("1 1 1")
		print("1 2 2")
		print("1 3 3")
		print("2 1 2")
		print("2 2 3")
		print("2 3 1")
		spec = False
	dJP = {}
	dJS = {}
	dPS = {}
	for i, j in itertools.product(range(1,(J+1)), range(1,(P+1))):
		JP.append((i,j))

	for i, j in itertools.product(range(1,(J+1)), range(1,(S+1))):
		JS.append((i,j))

	for i, j in itertools.product(range(1,(S+1)), range(1,(S+1))):
		PS.append((i,j))

	# print(JP)
	# print(JS)
	# print(PS)
	l1 = len(JP)
	l2 = len(JS)
	l3 = len(PS)
	# print("l1,l2,l3 :")
	# print(l1)
	# print(l2)
	# print(l3)

	for i in JP:
		for j in JS:
			for k in PS:
				dJP[i]=0
				dJS[j]=0
				dPS[k]=0
	# Peut etre le min des trois
	lpos = []
	m = len(JP)
	countJP = 0
	for i in JP:
		for j in JS:
			for k in PS:
				if ((i[0]==j[0]) and (i[1] == k[0]) and (j[1]==k[1])):
					if ((dJP[i]<K) and (dJS[j]<K) and (dPS[k]<K)):
						# print("i,j,k :")
						# print(i)
						# print(j)
						# print(k)
						dJP[i]+=1
						dJS[j]+=1
						dPS[k]+=1
						s = str(i[0]) + " " + str(i[1]) + " " + str(k[1])
						lpos.append(s)

						countJP +=1
	countJS = 0
	for j in JS:
		for i in JP:
			for k in PS:
				if ((i[0]==j[0]) and (i[1] == k[0]) and (j[1]==k[1])):
					if ((dJP[i]<K) and (dJS[j]<K) and (dPS[k]<K)):
						# print("i,j,k :")
						# print(i)
						# print(j)
						# print(k)
						dJP[i]+=1
						dJS[j]+=1
						dPS[k]+=1
						s = str(i[0]) + " " + str(i[1]) + " " + str(k[1])
						lpos.append(s)

						countJS +=1	

	countPS = 0
	for k in PS:
		for j in JS:
			for i in JP:
				if ((i[0]==j[0]) and (i[1] == k[0]) and (j[1]==k[1])):
					if ((dJP[i]<K) and (dJS[j]<K) and (dPS[k]<K)):
						# print("i,j,k :")
						# print(i)
						# print(j)
						# print(k)
						dJP[i]+=1
						dJS[j]+=1
						dPS[k]+=1
						s = str(i[0]) + " " + str(i[1]) + " " + str(k[1])
						lpos.append(s)

						countPS +=1

	# print("counts JP, JS, PS : ")
	# print(countJP)
	# print(countJS)
	# print(countPS)
	# print("---------")
	# print("J, P, S, K")
	# print(J,P,S,K)
	if (spec):
		sol = min(countJP,len(JP)*K)
		print(sol)
	spec=True
	nsol = 0
	for i in lpos:
		nsol +=1
		if (nsol<=sol):
			print(i)