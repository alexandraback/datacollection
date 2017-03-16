import math

t = input()
for i in range(t):
	N = int(raw_input())
	d = [0]*N
	n = [0]*N
	w = [0]*N
	e = [0]*N
	s = [0]*N
	d_d = [0]*N
	d_p = [0]*N
	d_s = [0]*N
	
	dict = {}
	
	for k in range(N):
		d[k],n[k],w[k],e[k],s[k],d_d[k],d_p[k],d_s[k] = map(int,raw_input().split())
	success = 0
	day = 0
	t = N
	while (t>0):
		bdict = {}
		for k in range(N):
			tsucc = False
			if d[k] == day:
				for j in range(w[k],e[k]):
					if not j in dict:
						#print j,i,day
						tsucc = True
						if j in bdict:
							bdict[j] = max(bdict[j],s[k])
						else:
							bdict[j] = s[k]
					elif dict[j] < s[k]:
						#print j,i,day
						tsucc = True
						if j in bdict:
							bdict[j] = max(bdict[j],s[k])
						else:
							bdict[j] = s[k]
				if tsucc:
					success = success+1
				if(n[k]>1):
					n[k] = n[k]-1
					d[k] = d[k]+d_d[k]
					w[k] = w[k]+d_p[k]
					e[k] = e[k]+d_p[k]
					s[k] = s[k]+d_s[k]
				else:
					t = t-1
		for j in bdict:
			dict[j] = bdict[j]
		day = day+1
	print "Case #"+str(i+1)+": "+str(success)