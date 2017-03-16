import sys

fin = open('C-large.in')
fout = open('Clarge.out', 'w')

T = int(fin.readline())
buf = []

def pre(upper):
	for cur in range(1, upper):
		sCur = str(cur)
		rec = set()
		for i in range(len(sCur) - 1):
			sNext = sCur[i + 1:] + sCur[:i + 1]
			iNext = int(sNext)
			if(iNext > cur) and (iNext <= upper):
				# print cur, iNext
				rec.add(iNext)
		buf.append(rec)
	

pre(2000000)

for idxT in range(T):
	A, B = map(int, fin.readline().split())
	ans = 0
	for cur in range(A, B):
		for k in buf[cur - 1]:
			if k <= B:
					ans += 1
	print "Case #%d: %s" % (idxT + 1, str(ans))
	fout.write("Case #%d: %s\n" % (idxT + 1, str(ans)))

fin.close()
fout.close()
