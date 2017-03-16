#!/usr/bin/python2

import math;

if __name__ == "__main__":
	T = (int)(raw_input());
	s = raw_input().split();
	R = (int)(s[0]);
	N = (int)(s[1]);
	M = (int)(s[2]);
	K = (int)(s[3]);
	su = [];
	for i in range(5**3):
		su.append({});
	for i in range(2, M + 1):
		for j in range(2, M + 1):
			for k in range(2, M + 1):
				s = "%d%d%d" % (i, j, k);
				num = [i, j, k];
				for l in range(0, 8):
					t = 1;
					for b in range(3):
						if ((l & (1 << b)) != 0):
							t = t * num[b];
					su[t - 1].setdefault(s, 0);
					su[t - 1][s] += 1;
	pr = [];
	for i in range(5**3):
		pr.append({});
		tot = 0;
		for x in su[i]:
			tot += su[i][x];
		for k in su[i].keys():
			pr[i][k] = math.log((float)(su[i][k]) / tot);
	print "Case #1:";
	for i in range(R):
		s = raw_input().split();
		res = pr[(int)(s[0]) - 1].copy();
		for i in range(1, len(s)):
			val = (int)(s[i]) - 1;
			tmp = res.copy();
			for k in tmp.keys():
				if (k not in pr[val]):
					del res[k];
			for k in pr[val]:
				if (k in res):
					res[k] += pr[val][k];
		bst = "222";
		fst = True;
		for k in res:
			if (fst):
				bst = k;
			elif (res[k] > res[bst]):
				bst = k;
		print bst;
