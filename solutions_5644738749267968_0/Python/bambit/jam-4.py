f = open('D-small.in')
T = int(f.readline())
for t in range(1, T+1):
	N = int(f.readline())
	Nfair = sorted(map(float, f.readline().split()))
	Kfair = sorted(map(float, f.readline().split()))
	
	Ndece = Nfair[:]
	Kdece = Kfair[:]

	#
	# Fair game
	#
	N_fair_points = 0
	for i in range(N):
		Nplay = Nfair[i]
		if Kfair[-1] < Nplay:
			Kfair.remove(Kfair[0])
			N_fair_points += 1
		else:
			for Kplay in Kfair:
				if Kplay > Nplay:
					Kfair.remove(Kplay)
					break
	
	#
	# Deceitful game
	#
	N_dece_points = 0
	while len(Ndece) != 0:
		if Ndece[0] > Kdece[0]:
			N_dece_points += 1
			Ndece.remove(Ndece[0])
			Kdece.remove(Kdece[0])
			continue
		else:
			Ndece.remove(Ndece[0])
			Kdece.remove(Kdece[-1])
	
	print 'Case #%d: %d %d' % (t, N_dece_points, N_fair_points)

