t = int(raw_input())
MAX = 2000000

def recycled(n):
	s = str(n)
	l = len(s)
	i = 0
	found = []
	
	for i in range(l-1):
		if s[l - (i+1)] != '0':
			yld = int(s[l-(i+1):] + s[:l-(i+1)])
			if yld not in found:
				found.append(yld)
				yield yld
	
def pairs(a,b):
	cnt = 0
	for i in range(a,b+1):
		for x in recycled(i):
			if x>i and x<=b:
				#print (i,x)
				cnt +=1
	return cnt

for T in range(t):
	s = map(int, str(raw_input()).split(' '))
	print ("Case #" + str(T+1) + ": " + str(pairs(s[0],s[1])))
	
	'''
	for i in range(len(lst)):
		for j in range(i+1,len(lst)):
			if lst[i][0]==lst[j][0] and lst[i][1]==lst[j][1]:
				print("duplicate" + str(lst[i]))
	'''
	