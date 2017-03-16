T = int(raw_input())

def licz_koszt(sum_rozm, mot):
	sum_rozm2 = int(sum_rozm)
	koszt = 0
	while sum_rozm2 <= mot:
		#print "@", sum_rozm2
		sum_rozm2+=sum_rozm2-1
		koszt+=1
	sum_rozm2 += mot
	return koszt, sum_rozm2
def solve(Am, A, motes):
	if Am == 1:
		return len(motes)
	motes = sorted(motes)
	#print Am, motes

	costs = []
	sum_rozm = Am
	sum_koszt = 0

	costs.append((0, A))
	for mi in range(len(motes)):
		#print "$", sum_rozm, motes[mi]
		if motes[mi] < sum_rozm:
			sum_rozm+=motes[mi]
		else:
			koszt, rozmiar = licz_koszt(sum_rozm, motes[mi])
			sum_rozm=rozmiar
			sum_koszt += koszt
		costs.append((sum_koszt, len(motes)-mi-1)) #SPRAWDZ CZY DOBRA ROZNICA
		#print sum_rozm, sum_koszt, (len(motes)-mi-1)
	#print costs
	added_costs = [a+b for a,b in costs]
	returnval = 0
	if not added_costs:
		returnval = 0
	else:
		returnval = min(added_costs)
	#print returnval
	return returnval

for t in range(T):
	Am, A = [int(i) for i in raw_input().split(' ')]
	motes = [int(i) for i in raw_input().split(' ')]
	print "Case #%d: %d" % (t+1, solve(Am, A, motes))
