
n = 16
m = 50


p = []

def init():
	k = 10 ** (n / 2)
	k = min(k,2**20)
	d = [0] * (k + 1)
	for i in range(2,k + 1):
		if d[i] == 0:
			p.append(i)
			for j in range(i + i,k + 1,i):
				d[j] = 1
	# print p		

def check(x):
	flag = 1
	res = []
	for i in range(2,11):
		y = int(x,i)
		# print x,y
		for z in p:
			if y % z == 0 and y != z:
				# print y,z,y/z*z
				res.append(str(z))
				break
		else:
			flag = 0
			break
	print x,flag
	return flag,res
	
init()
stt = 2 ** (n - 1) + 1
# stt = int("100011",2)
f = open("data.out","w")
f.write("Case #1:\n")
while m > 0:
	s = bin(stt)[2:]
	res,lst = check(s)
	if res == 1:
		f.write(s + " " + " ".join(lst) + "\n")
		m -= 1
	stt += 2
	# break
	