import sys

T = int(raw_input())

for t in range(1, T+1):
	J,P,S,K = map(int, raw_input().split())

	al = J*P*S
	jp = K*J*P
	#ps = K*P*S
	#js = K*J*S

	#y = min(al, jp, ps, js)
	y = min(al, jp)

	print 'Case #%d: %d' % (t, y)

	#print 'Case #%d: %d' % (t, y)

	#j_max = K if y == ps else J
	#p_max = K if y == js else P
	#s_max = K if y == jp else S

	already = {} # jp,ps,js
	i = 0
	l = []

	if y == al:
		for j in range(1, J+1):
			for p in range(1, P+1):
				for s in range(1, S+1):
					print j,p,s
					i += 1
	else:
		for j in range(1, J+1):
			s = j
			for p in range(1, P+1):
				while True:
					jp = ','.join(map(str, [j, p]))
					ps = ','.join(map(str, [p, s]))
					js = ','.join(map(str, [j, s]))
					if not jp in already:
						already[jp] = [0,0,0]
					if not ps in already:
						already[ps] = [0,0,0]
					if not js in already:
						already[js] = [0,0,0]
	
					if already[jp][0] >= K or already[ps][1] >= K or already[js][2] >= K:
						break
	
					print j,p,s
					i += 1
					s = 1 if s == S else (s + 1)
					already[jp][0] += 1
					already[ps][1] += 1
					already[js][2] += 1

	if y != i: print 'ERROR', y, i