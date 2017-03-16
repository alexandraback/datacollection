import sys
import time


def get_digit_set(n):
	d = []
	while n > 0:
		d.append(n % 10)
		n /= 10

	return set(d)


def print_last_digit_before_sleep(n):
	if n == 0:
		return "INSOMNIA"

	seen = get_digit_set(n)
	mult = 2
	while len(seen) < 10:
		seen |= get_digit_set(n * mult)
		mult += 1

	return str(n * (mult - 1))

if __name__ == '__main__':
	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		n = int(lines[i+1])
		try:
			out.write("Case #%d: %s\n" % (i + 1, print_last_digit_before_sleep(n)))
		except:
			print "exception in line %d" % i+1
			raise

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)


