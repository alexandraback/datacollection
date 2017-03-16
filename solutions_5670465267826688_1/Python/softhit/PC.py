import sys

def multt(a, sign, b):
	if a == '1':
		return (b, sign)
	if b == '1':
		return (a, sign)
	if a == 'i' and b == 'j':
		return ('k', sign)
	if a == 'j' and b == 'i':
		return ('k', -1 * sign)
	if a == 'k' and b == 'i':
		return ('j', sign)
	if a == 'i' and b == 'k':
		return ('j', -1 * sign)
	if a == 'j' and b =='k':
		return ('i', sign)
	if a == 'k' and b =='j':
		return ('i', -1 * sign)
	if a == 'i' and b == 'i':
		return ('1', -1 * sign)
	if a =='j' and b =='j':
		return ('1', -1 * sign)
	if a == 'k' and b =='k':
		return ('1', -1 * sign)

cases = int(raw_input())
for c in xrange(cases):
    # read in misc problem constants
    L, X = map(int, raw_input().split())
    S = map(str, raw_input())

    res = '1'
    sign = 1

    period = X

    mata = False
    matb = False
    cc = False

    for i in xrange(X):
    	for j in S:
            res, sign = multt(res, sign,  j)

        if res == '1' and sign == 1:
            period = i + 1
            break;

    l = X % period
    mat = '1'
    sign2 = 1
    for i in xrange(2 * period):
        for j in S:
            mat, sign2 = multt(mat, sign2, j)
            if mat == 'i' and sign2 == 1:
                mata = True
            if (mata == True and mat == 'k' and sign2 == 1):
                matb = True

    if (l > 0):
        res = '1'
        sign = 1
        for i in xrange(l):
            for j in S:
                res, sign = multt(res, sign,  j)

    if mata == True and matb== True and res == '1' and sign == -1:
        print "Case #%d: YES" % (c+1)
    else:
        print "Case #%d: NO" % (c+1)
