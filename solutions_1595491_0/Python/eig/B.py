def main(S,p,points):
	points.sort()
	points.reverse()
	count = 0

	if p==0:
		return len(points)
	elif p==1:
		return len( filter((lambda x:x!=0), points ) )

	for summ in points:
		if (summ-1)/(p-1)>=3:
			count+=1
		elif ((p==2 and summ>=2) or (summ-2)/(p-2)>=3) and S>0:
			count+=1
			S-=1
		else:
			break
	return count

if __name__ == '__main__':
	import sys

	T = int(sys.stdin.readline())
	for i in xrange(T):
		array = map(int, sys.stdin.readline().split(' '))
		
		S = array[1]
		p = array[2]
		points = array[3:]

		res = main(S,p,points)
		print "Case #%d: %d" % (i + 1,res)
