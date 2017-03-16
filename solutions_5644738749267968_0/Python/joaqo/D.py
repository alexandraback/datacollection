T = int(raw_input())
for u in range(T):
	(N) = [int(j) for j in raw_input().split()]
	naomi = [float(j) for j in raw_input().split()]
	ken = [float(j) for j in raw_input().split()]
	naomi.sort();
	ken.sort();
	#print(naomi)
	#print(ken)

	deceptive = 0
	pivot1 = 0
	pivot2 = 0
	for i in range(len(naomi)):
		if naomi[pivot1]>ken[pivot2]:
			deceptive += 1
			pivot1 += 1
			pivot2 += 1
		else:
			pivot1 += 1

	nondeceptive = 0
	pivot1 = 0
	pivot2 = 0
	for i in range(len(naomi)):
		if pivot2<len(naomi):
			while pivot2<len(naomi):
				if naomi[pivot1]>ken[pivot2]:
					pivot2 += 1
					if pivot2==len(naomi):
						nondeceptive += 1
				else:
					pivot1 += 1
					pivot2 += 1
					break
		else:
			nondeceptive += 1

	print("Case #"+`u+1`+": "+`deceptive`+" "+`nondeceptive`)