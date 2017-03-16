import sys
from sys import argv

def getfactors(num):
	list = [2]
	for n in range(3,  num):
		notdetected = True
		for i in list:
			if n%i == 0:
				notdetected = False
				break
		if notdetected:
			list.append(n)
	return list


def solve(N, P, factors):
	found = 0
	for num in range (2**(N-2), 2**(N-1)-1):
		ans=[]
		num = bin(num)
		in_str = str(num[2:])
		in_str = in_str+'1'
		count = 0
		for base in range (2, 11):
			interpreted = int(in_str, base)
			not_detected = True
			for f in factors:
				if interpreted % f == 0:
					ans.append(f)
					not_detected = False
					count = count + 1
					break
			if not_detected:
				break
		if count == 9:
			text = ' '.join(str(e) for e in ans)
			print(in_str, text)
			found = found + 1
		del ans[:]
		if found == P:
			break

f = open("c.txt", 'r')
T = f.readline()
NP = f.readline()
f.close()
tokens = NP.split();
N = tokens[0]
P = tokens[1]
list = getfactors(10000)
print("Case #1:")
solve(int(N), int(P), list);
