import random

LEN = 16
SAMPLES = 50


def value_in_base(n, b):
	acc = 0
	for v in n:
		acc *= b
		acc += v
	return acc


def f():
	candidate = [1] + [random.randint(0, 1) for _ in range(LEN - 2)] + [1]
	factors = []
	for base in range(2, 11):
		value = value_in_base(candidate, base)
		f = -1
		for i in range(2, min(1000000, value)):
			if value % i == 0:
				f = i
				break
		if f < 0:
			return None
		factors.append(f)
	return tuple([value_in_base(candidate, 10)] + factors)



def main():
	d = set()
	while True:
		res = f()
		if not res:
			continue
		d.add(res)
		if len(d) == SAMPLES:
			break
	print 'Case #1:'
	for jamcoin in d:
		print ' '.join(str(x) for x in jamcoin)



if __name__ == '__main__':
	main()