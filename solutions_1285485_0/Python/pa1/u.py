import math

def gcd(a,b):
	if b == 0:
		return a
		
	return gcd(b,a%b)

T = int(raw_input().strip())
cs = 1
while cs <= T:
	ln = raw_input()
	#print ln
	H,W,D = ln.split()
	H = int(H)
	W = int(W)
	D = int(D)
	i = 0
	while i < H:
		ln = raw_input().strip().find("X")
		if ln != -1:
			l = ln - 0.5
			r = W - 2 - l
			t = i - 0.5
			b = H - 2 - t
		i = i+1
	s_h = l + r
	s_v = t + b
	inclined = {}
	i = 0
	H_R = []
	H_L = []
	while i*s_h <= D:
		xx = i*s_h + l
		yy = i*s_h + r
		if i%2 == 0:
			H_R.append(r + yy)
			H_L.append(l + xx)
		else:
			H_R.append(r + xx)
			H_L.append(l + yy)
		i = i + 1
			
	i = 0
	V_T = []
	V_B = []
	while i*s_v <= D:
		xx = i*s_v + t
		yy = i*s_v + b
		if i%2 == 0:
			V_B.append(b + yy)
			V_T.append(t + xx)
		else:
			V_B.append(b + xx)
			V_T.append(t + yy)
		i = i + 1

	#print V_T
	i = 0
	ans = 0
	inclined = {}
	while i < len(V_T):
		j = 0
		while j < len(H_R):
			d_2 = V_T[i]*V_T[i] + H_R[j]*H_R[j]
			d = math.sqrt(d_2)
			if d <= D:
				g = gcd(V_T[i],H_R[j])
				k = str(V_T[i]/g) + '_' + str(H_R[j]/g)
				if not inclined.has_key(k):
					ans = ans + 1
					inclined[k] = True
			j = j + 1
		i = i + 1

	i = 0
	inclined = {}
	while i < len(V_T):
		j = 0
		while  j < len(H_L):
			d_2 = V_T[i]*V_T[i] + H_L[j]*H_L[j]
			d = math.sqrt(d_2)
			if d <= D:
				g = gcd(V_T[i],H_L[j])
				k = str(V_T[i]/g) + '_' + str(H_L[j]/g)
				if not inclined.has_key(k):
					ans = ans + 1
					inclined[k] = True
			j = j + 1
		i = i + 1
		
	i = 0
	inclined = {}
	while i < len(V_B):
		j = 0
		while j < len(H_R):
			d_2 = V_B[i]*V_B[i] + H_R[j]*H_R[j]
			d = math.sqrt(d_2)
			if d <= D:
				g = gcd(V_B[i],H_R[j])
				k = str(V_B[i]/g) + '_' + str(H_R[j]/g)
				if not inclined.has_key(k):
					ans = ans + 1
					inclined[k] = True
			j = j + 1
		i = i + 1

	i = 0
	inclined = {}
	while i < len(V_B):
		j = 0
		while j < len(H_L):
			d_2 = V_B[i]*V_B[i] + H_L[j]*H_L[j]
			d = math.sqrt(d_2)
			if d <= D:
				g = gcd(V_B[i],H_L[j])
				k = str(V_B[i]/g) + '_' + str(H_L[j]/g)
				if not inclined.has_key(k):
					ans = ans + 1
					inclined[k] = True
			j = j + 1
		i = i + 1
	
	
	if V_T[0] <= D:
		ans = ans + 1
	
	if V_B[0] <= D:
		ans = ans + 1
		
	if H_R[0] <= D:
		ans = ans + 1
		
	if H_L[0] <= D:
		ans = ans + 1
	
	print "Case #" + str(cs) + ": " + str(ans)
	cs = cs + 1