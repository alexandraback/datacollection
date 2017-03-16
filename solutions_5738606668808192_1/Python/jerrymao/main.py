import sympy
import time
import sys

time_limit = 0.5
def foo(n):
	idx = -1
	while n[idx] == '1':
		idx -= 1
	n = n[:idx] + '1' + (-2-idx)*'0' + '1'
	return n

def current_milli_time():
	return int(round(time.time()*1000))

n = '10000000000000000000000000000001'
rem = 500
while True:
	print(n, file=sys.stderr)
	div = []
	ok = True
	for base in range(2, 11):
		val = int(n, base)
		if sympy.isprime(val):
			ok = False
			break
		num = None
		A = 3
		b = 3
		start_time = current_milli_time()
		while num == None:
			num = sympy.pollard_pm1(val, B=b, a=A)
			A += 2
			b += 1
			end_time = current_milli_time()
			if end_time-start_time >= 1000*time_limit:
				ok = False
				break
		if not ok:
			break
		div += [num]
	if ok:
		print (n, end="")
		for i in div:
			print (" "+str(i), end="")
		print (str(rem), file=sys.stderr)
		print ()
		rem -= 1
		if rem == 0:
			break
	n = foo(n)
