T = input()
for case in range(1, T+1):
	N = int(raw_input())
	attacks = []
	for i in range(N):
		d, n, w, e, s, delta_d, delta_p, delta_s = map(int, raw_input().split())
		for j in range(n):
			attacks.append((d, 2*w, 2*e, s, i))
			d += delta_d
			w += delta_p
			e += delta_p
			s += delta_s
	attacks.sort()
	height = [0]*1200
	height2 = [0]*1200
	i = 0
	ans = 0
	while i < len(attacks):
		j = i
		height2 = list(height)
		while j < len(attacks) and attacks[j][0] == attacks[i][0]:
			w, e, s = attacks[j][1], attacks[j][2], attacks[j][3]
			good = False
			for p in range(w+300, e+301):
				if height[p] <s:
					height2[p] = max(s, height2[p])
					good = True
			if good:
				#print 'day: %d tribe: %d' % (attacks[j][0], attacks[j][4])
				ans += 1
			j += 1
		height = height2
		i = j
	print 'Case #%d: %d' % (case, ans)