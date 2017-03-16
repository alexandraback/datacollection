
def shortest_run(n) :

	if n <= 11:
		return n

	for i in range(2,15):
		if n <= 10 ** i:
			target = ""

			res = 1
			if n / 10**(i/2) == 10**((i-1)/2):
				l = i-1
				target = "9"*(l/2) + "0" * (l - l/2 - 1) + "1"
				target = target[::-1]
				res = 0
			else :
				big_half = str(n)[:len(str(n))/2]
				big_half = big_half[::-1]
				target = "1" + ("0"*(len(str(n))/2-(1 if len(str(n)) % 2 == 0 else 0))) + big_half
			res = res + shortest_run(int(target)) + (n - int(target[::-1]))
			print n,target, target[::-1], res

			return res

with open("input",'r') as inp, open("output",'w') as out:

	T = int(inp.readline())
	for t in range(1,T+1):
		N = int(inp.readline())
		out.write("Case #{0}: {1}\n".format(t,shortest_run(N)))