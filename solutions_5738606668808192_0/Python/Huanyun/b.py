bases = [[] for i in range(11)]
for i in range(2,11,2):
	a = 1

	for j in range(1,32):
		bases[i].append(a)
		b = a * i
		a = b

# print bases

counts = 0
digits = 16
max_count = 50

def isPrime(string,base):

	num = 0
	for i, c in  enumerate(string):
		if c == '1':
			num += bases[base][i]

	i = 3
	while (i * i <= num):
		if num % i == 0:
			# print(string + " base " + str(base) + " to " + str(num) + " is devied by " + str(i))
			return i
		i += 1
	return 0



def check(string):
	global counts
	global debug
	s = sum([int(c) for c in string])
	if s % 2 != 0:
		return

	rets = []
	for i in range(2,11):
		if i % 2 == 1:
			rets.append("2")
			continue
		p = isPrime(string,i)
		if p == 0:
			return
		rets.append(str(p))


	print(string[::-1] + " " + " ".join(rets))
	counts += 1

def construct(n, string):
	global counts
	global max_count
	global digits
	if counts >= max_count:
		return

	if n == digits:
		construct(n-1, "1")
	elif n == 1:
		check("1"+string)
	else:
		construct(n-1, "1"+string)
		construct(n-1, "0"+string)

print("Case #1:")
construct(digits,"")
