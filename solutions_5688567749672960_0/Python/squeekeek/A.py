def main():
	testcases = int(raw_input())
	
	dptable = [-1] * 1000001
	dptable[0:2] = [0, 1]
	
	for i in range(1, 1000001):
		nrev = int(str(i)[::-1])
		
		if nrev < i and str(i)[-1] != '0':
			dptable[i] = min(dptable[i - 1], dptable[nrev]) + 1
		else:
			dptable[i] = dptable[i - 1] + 1
	
	for t in range(1, testcases + 1):
		ndest = int(raw_input())
		
		print "Case #" + str(t) + ":", dptable[ndest]

if __name__ == "__main__":
	main()