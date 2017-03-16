L =["ZERO",
"ONE",
"TWO",
"THREE",
"FOUR",
"FIVE",
"SIX",
"SEVEN",
"EIGHT",
"NINE"
]





def solve(s):
	dig = ""
	for n in range(10):
		while True:
			Q = [0, 2, 4, 6, 8, 5, 7, 9, 3, 1]
			U = "ZWUXGFVITO"
			if U[n] in s:
				#print U[n], n, s
				for k in L[Q[n]]:
					s = s.replace(k, "", 1)
				dig +=str( Q[n])
				
			else: break				
	return "".join(sorted(dig))
		
	


CASES = int(raw_input())

case = 1
for i in range(CASES):
	print ("Case #%d:" % case), solve(raw_input())
	case += 1
