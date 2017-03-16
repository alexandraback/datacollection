#!/usr/bin/python2
import math;

if __name__ == "__main__":
	tn = (int)(raw_input());
	for ti in range(tn):
		s = raw_input().split();
		r = (int)(s[0]);
		t = (int)(s[1]);
		x = 0;
		y = (int)(math.sqrt(t * t + r) + 5) / 4 + 1;
		while (x < y):
			mid = x + ((y - x + 1) / 2);
			if ((2 * r + 2 * mid + 1) * (mid + 1) > t):
				y = mid - 1;
			else:
				x = mid;
		print "Case #%d: %d" % (ti + 1, x + 1);
