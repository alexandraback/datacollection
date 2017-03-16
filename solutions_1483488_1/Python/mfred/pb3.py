input = """50
1049802 1946314
1019242 1999787
332841 815293
1443938 1907548
5125 9748
1037227 1960407
1053187 1952673
1043225 1910832
100000 100000
351349 556470
68 80
116204 961036
504 844
1086291 1964681
100000 999999
21207 36868
38 50
54134 64312
1526010 1747987
1736162 1783904
100000 100001
10486 11651
1820549 1880905
1097653 1971323
1087139 1993152
1090695 1961364
4541 8166
1046409 1315179
897387 957090
1024733 1940114
1000415 1945733
534 685
1019180 1921115
1076227 1860470
502 748
10000 99999
7821 9852
353200 479493
3 8
4977 7152
36645 46007
1166938 1166938
45802 72650
1085149 1982470
1037947 1935060
1634839 1802893
1056643 1989496
1001424 1975827
752384 752384
778195 833983"""

lines = input.split("\n")

def shiftOnce(s):
	return s[len(s)-1]+s[:len(s)-1]

i = 0
for l in lines[1:]:
	
	# Input i
	inp = l.split(" ")
	A = int(inp[0])
	B = int(inp[1])
	
	n = len(str(B))
	
	classes = [0 for j in range(0,B+1)]
	# classes[i] represente le card de la classes d'equivalence de i, si i est le plus petit representant de sa classe
	
	for n in range(A,B):
		current = shiftOnce(str(n))
		if int(current) >= A and int(current) <= B:
			minimum = min(int(current),n)
			card = 1
		else:
			minimum = n
			card = 0
		while (current != str(n)):
			current = shiftOnce(str(current))
			c = int(current)
			if c >= A and c <= B:
				minimum = min(c,minimum)
				card += 1
		classes[minimum] = card
	
	r = 0
	for j in classes:
		r += j*(j-1)/2
	
	print "Case #"+str(i+1)+": "+str(r)
	i += 1