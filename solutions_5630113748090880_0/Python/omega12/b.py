def solve(info):
	n=int(info)
	p=list()
	for x in range(0,2*n-1):
		q=map(int,raw_input().split(' '))
		for z in q:
			p.append(z)
	h=f5(p)
	m=list()
	for q in h:
		if p.count(q)%2!=0:
			m.append(q)
	m.sort()
	return " ".join(map(str,m))


def f5(seq, idfun=None): 
   # order preserving
   if idfun is None:
       def idfun(x): return x
   seen = {}
   result = []
   for item in seq:
       marker = idfun(item)
       # in old Python versions:
       # if seen.has_key(marker)
       # but in new ones:
       if marker in seen: continue
       seen[marker] = 1
       result.append(item)
   return result

if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases + 1):
        info = raw_input()
        print("Case #%i: %s" % (caseNr, solve(info)))
