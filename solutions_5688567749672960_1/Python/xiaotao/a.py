import string;

def f(n):
	result = 1e100;
	s = "%d" %n;
	if (len(a) < len(s)): return 0;
	for i in range(1, len(s)):
		part1 = s[0:i];
		part2 = s[i:];

		temp1 = string.atoi(part1);
		remp1 = string.atoi(part1[::-1]);
		temp2 = string.atoi(part2);
		remp2 = string.atoi(part2[::-1]);

		if (temp2 <> 0):
			result = min(result, temp2 + remp1);
	result = min(result, n - 10 ** (len(s) - 1));
	return result + a[len(s) - 1];
	return 0;

tdnum = input();
a = [1, 10, 29, 138, 337, 1436, 3435, 14434, 34433, 144432, 344431, 1444430, 3444429, 14444428, 34444427];
for i in range(1, tdnum + 1):
	n = input();
	print "Case #%d: %d" %(i, min(f(n), f(n - 1) + 1));
