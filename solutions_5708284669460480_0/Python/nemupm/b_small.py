import sys
sys.setrecursionlimit(1000)

def base10to(n, b):
	if(int(n/b)):
		return base10to(int(n/b), b) + str(n%b)
	return str(n%b)

T = input()
for _ in xrange(T):
	k,l,s = map(int,raw_input().split())
	keyboard = raw_input()
	target = raw_input()

	max_banana = 0
	total_pay_banana = 0
	for i in xrange(len(keyboard) ** s):
		monkey_string = ""
		pay_banana = 0
		#print base10to(i,len(keyboard))
		b = base10to(i,len(keyboard))
		b = '0' * (s-len(b)) + b
		for char in b:
			monkey_string += keyboard[int(char)]
		for i in xrange(s - len(target) + 1):
			if monkey_string[i:i+len(target)] == target:
				pay_banana += 1
		if max_banana < pay_banana:
			max_banana = pay_banana
		total_pay_banana += pay_banana
		#print pay_banana
	ans = float(max_banana) - float(total_pay_banana) / float(len(keyboard) ** s)
	#print max_banana
	#print total_pay_banana
	#print float(total_pay_banana) / float(len(keyboard) ** s)

	print "Case #%d: %f" % (_+1,ans)