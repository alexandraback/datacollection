mappings = {}

def getPairs(a, b, s):
	for i in range(1, len(s)):
		if(s[i] == '0'):
			continue
		tmp = s[i:] + s[:i]
		if tmp > a and tmp > s and tmp <= b:
			mappings[s+tmp] = tmp
	
if __name__=="__main__":
	testcases = input()
	
	for i in range(1, testcases+1):
		line = raw_input().split(" ")		
		a = line[0]
		b = line[1]
		aa = int(a)
		bb = int(b)		
		it = aa
		result = 0
		while it < bb:
			getPairs(a, b, str(it))
			it += 1
		print "Case #" + str(i) + ": " + str(len(mappings.keys()))
		mappings = {}
