import sys

ar = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
nums = [0,1,2,3,4,5,6,7,8,9]
fa = ['z','', 'w', '', 'u','', 'x', '', 'g', '']
fa2 = ['', 'o', '', 't', '', 'f', '', 'v', '', '']

def strred(s, sub):
    d1 = dict()
    for c in s:
	if not c in d1:
	    d1[c] = 0
	d1[c] += 1

    d2 = dict()
    for c in sub:
	if not c in d2:
	    d2[c] = 0
	d2[c] += 1

    for elem in d2:
	try:
	    d1[elem] -= d2[elem]
	except:
	    print s
	    print sub
	    sys.exit(1)
    res = ''
    for elem in d1:
	for i in xrange(d1[elem]):
	    res += elem
    return res

def main():
    f = open(sys.argv[1])
    t = int(f.readline().strip())
 
    for kk in xrange(t):
	line = f.readline()
	line = line.strip().lower()
	res = []
	for i in xrange(len(ar)):
	    while len(fa[i]) > 0 and fa[i] in line:
		res.append(nums[i])
		line = strred(line, ar[i])
	
	for i in xrange(len(ar)):
	    while len(fa2[i]) > 0 and fa2[i] in line:
		res.append(nums[i])
		line = strred(line, ar[i])

	if len(line) > 0:
	    for i in xrange(len(line)/4):
		res.append(9)

	res = sorted(res)
	resstr = ""
	for elem in res:
	    resstr += str(elem)
	print "Case #"+str(kk+1)+": "+resstr

    f.close()

if __name__ == "__main__":
    main()
