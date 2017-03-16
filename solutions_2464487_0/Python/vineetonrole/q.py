test = input()
case = 1;
while test:
	x = raw_input()
	r,t = x.split()
	r = int(r)
	t = int(t)
	low = 1
	high = 1000000001
	while(low<=high):
		mid = (int)(low+high)/2;
		d = 2*mid*mid + mid*(2*r-1) - t;
		if d<=0:
			ans = mid
			low = mid + 1
		else:
			high = mid - 1
	print 'Case #%d: %d' %(case,ans)
	test -= 1
	case += 1
