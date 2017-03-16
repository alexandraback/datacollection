def getPrev(txt, k):
	while(k >= 0 and not(txt[k] in vowels)):
		k -= 1
	return k + 1


def calc(txt, n):
	ans = 0
	a = [0 for i in range(len(txt))]
	last = getPrev(txt, n - 1)
	for i in range(n - 1, len(txt)):
		if(not(txt[i] in vowels)):
			if(i - last + 1 >= n):
				a[i] = i - n + 2
			else:
				a[i] = a[i - 1]
		else:
			a[i] = a[i - 1]
			last = i + 1

		ans += a[i]

#	print a
	return ans

def solve(txt, n):
	return calc(txt, n)

T = input()
vowels = ['a', 'e', 'i', 'o', 'u']
for i in range(T):
	line = raw_input().split()
	print "Case #" + str(i + 1) + ": " + str(solve(line[0], int(line[1])))
