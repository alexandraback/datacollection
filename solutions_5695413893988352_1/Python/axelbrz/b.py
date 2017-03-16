f = open("b.in")
d = f.read().strip().split("\n")[1:]
f.close()

def ext(a,b):
	return (abs(int(a)-int(b)),a,b)

def dp(s1,s2,i = 0, j = -1):
	global mem
	
	if len(s1) == 0:
		return s1, s2
	
	if i == 0:
		
		if s1[0] == "?" and s2[0] == "?":
			a,b=dp(s1[1:],s2[1:])
			
			return min([
				ext("0"+a,"0"+b),
				ext("1"+a,"0"+b),
				ext("0"+a,"1"+b)
			])[1:3]
		
		
		elif s1[0] == "?":
			
			opts = []
			
			
			
			if s2[0] != "0": opts.append(str(int(s2[0])-1))
			else: opts.append("1")
			opts.append(s2[0])
			if s2[0] != "9": opts.append(str(int(s2[0])+1))
			else: opts.append("0")
			
			return min([
				ext(*dp(opts[0]+s1[1:], s2)),
				ext(*dp(opts[1]+s1[1:], s2)),
				ext(*dp(opts[2]+s1[1:], s2))
			])[1:3]
			
		
		elif s2[0] == "?":
			opts = []
			
			
			
			if s1[0] != "0": opts.append(str(int(s1[0])-1))
			else: opts.append("1")
			opts.append(s1[0])
			if s1[0] != "9": opts.append(str(int(s1[0])+1))
			else: opts.append("0")
			
			return min([
				ext(*dp(s1, opts[0]+s2[1:])),
				ext(*dp(s1, opts[1]+s2[1:])),
				ext(*dp(s1, opts[2]+s2[1:]))
			])[1:3]
		else:
			# both fixed
			if s1[0] < s2[0]:
				return s1[0].replace("?", "9"), s2[0].replace("?", "0")
			elif s1[0] > s2[0]:
				return s1[0].replace("?", "0"), s2[0].replace("?", "9")
			else:
				a,b = dp(s1[1:], s2[1:])
				return s1[0]+a,s2[0]+b
				
				
	



o = open("b.out", "w")
for i in xrange(len(d)):
	s = d[i].split(" ")
	
	mem = {}
	
	
	sol = dp(s[0], s[1])
	
	ln = "Case #%d: %s" % (i + 1, " ".join(sol))
	
	print ln
	o.write(ln + "\n")
o.close()
