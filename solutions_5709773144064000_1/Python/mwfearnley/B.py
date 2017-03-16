#from fractions import Fraction
Fraction = float

def cookie(C, F, X):
	t = Fraction(0)
	cookies = 0
	rate = Fraction("2")
	besttime = t + X / rate
	
	#print("t: {0}, Rate: {1}, X: {2}, time: {3}".format(t, rate, X, besttime))
	done = False
	while not done:
		t += (C-cookies) / rate
		rate += F
		cookies = 0
		
		time = t + (X-cookies) / rate
		#print("t: {0}, Rate: {1}, X: {2}, time: {3}".format(t, rate, X, time))
		if time < besttime:
			besttime = time
		else:
			done = True
	#print(besttime)
	return besttime

with open("B-large.in") as fi:
	with open("B-large.out", "w") as fo:
		n = int(fi.readline())
		for i in range(n):
			C, F, X = (Fraction(n) for n in fi.readline().split())
			output = "Case #{0}: {1}".format(i+1, float(cookie(C, F, X)))
			print(output, file = fo)
