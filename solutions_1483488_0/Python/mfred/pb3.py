input = """50
110 956
177 933
170 923
120 932
143 979
173 988
181 938
100 101
132 934
187 931
6 9
107 959
121 991
744 744
100 999
104 947
100 999
178 938
112 948
150 917
281 493
463 900
111 973
449 916
118 927
143 932
146 956
175 997
172 917
183 939
159 937
50 92
155 935
113 927
130 992
357 357
34 37
132 925
188 923
139 923
145 942
189 973
162 995
166 996
10 10
183 938
135 941
148 944
175 997
174 982"""

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
			if int(current) >= A and int(current) <= B:
				minimum = min(int(current),minimum)
				card += 1
		classes[minimum] = card
	
	r = 0
	for j in classes:
		r += j*(j-1)/2
	
	print "Case #"+str(i+1)+": "+str(r)
	i += 1