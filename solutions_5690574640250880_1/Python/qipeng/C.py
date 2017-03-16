with open('C-large.in') as f:
	cases = int(f.readline())

	for i in range(cases):
		data = [int(x) for x in f.readline().split()]

		R = data[0]; C = data[1]; M = data[2]

		diff = R * C - M;

		print "Case #%d:" % (i+1)
		if diff <= 0:
			print "Impossible"
		elif diff == 1:
			for r in range(R-1):
				print "*" * C

			print "*" * (C-1) + "c"
		elif R == 1:
				print "*" * M + '.' * (C-M-1) + "c"
		elif C == 1:
			for j in range(M):
				print "*"
			for j in range(R-M-1):
				print "."
			print "c"
		else:
			plot = [[1]*C for t in range(R)]

			plot[0][0]=0
			plot[0][1]=0
			plot[1][1]=0
			plot[1][0]=0

			diff -= 4

			r = 0; c = 0

			dx = [-1,1,0,0,-1,-1,1,1]
			dy = [0,0,-1,1,-1,1,-1,1]

			worked = True
			while diff > 0 and worked:
				worked = False
				for di in range(8):
					nr = r + dx[di]; nc = c + dy[di]
					if nr < 0 or nc < 0 or nr >= R or nc >= C:
						continue

					gain = 0
					for j in range(8):
						nnr = nr + dx[j]; nnc = nc + dy[j]
						if nnr < 0 or nnc < 0 or nnr >= R or nnc >= C:
							continue

						gain += plot[nnr][nnc]

					if gain > diff or diff - gain == 1 or gain == 0: continue

					for j in range(8):
						nnr = nr + dx[j]; nnc = nc + dy[j]
						if nnr < 0 or nnc < 0 or nnr >= R or nnc >= C or plot[nnr][nnc]==0:
							continue

						plot[nnr][nnc] = 0

					worked = True
					diff -= gain
					r = nr; c = nc
					
					break

			lastr = r; lastc = c;

			for r in range(R):
				for c in range(C):
					if diff > 0 and plot[r][c] == 0:
						gain = 0
						for di in range(8):
							nr = r + dx[di]; nc = c + dy[di]
							if nr < 0 or nc < 0 or nr >= R or nc >= C:
								continue

							gain += plot[nr][nc]

						if gain == diff:
							for di in range(8):
								nr = r + dx[di]; nc = c + dy[di]
								if nr < 0 or nc < 0 or nr >= R or nc >= C:
									continue

								plot[nr][nc] = 0

							diff = 0

			if diff != 0:
				print "Impossible"
			else:
				plot[0][0] = -1;
				for r in range(R):
					sr = ""
					for c in range(C):
						if plot[r][c] < 0:
							sr += "c"
						elif plot[r][c] > 0:
							sr += "*"
						else:
							sr += "."

					print sr