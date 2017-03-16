num = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
dis = ['Z', None, 'W', None, None, None, 'X', None, 'G', None]

# one (t)hree four five seven nine
# one fou(r) five seven nine
# (o)ne (f)ive seven nine
# n(i)ne se(v)en 

def checkFor(index, letter, d):
    global op
    ctr = d.get(letter, 0)
    if(ctr):
        for c in num[index]:
            d[c] -= ctr
        op.extend([index for i in range(ctr)])

for cases in range(1, int(input()) + 1):
	s = input()
	d = {}
	ans = 0
	op = []
	for c in s:
	    d[c] = d.get(c,0) + 1
	
	checkFor(0, 'Z', d)
	checkFor(2, 'W', d)
	checkFor(6, 'X', d)
	checkFor(8, 'G', d)
	checkFor(3, 'T', d)
	checkFor(4, 'R', d)
	checkFor(1, 'O', d)
	checkFor(5, 'F', d)
	checkFor(9, 'I', d)
	checkFor(7, 'V', d)
	
	print('Case #%d:' % (cases,), ''.join([str(x) for x in sorted(op)]))
