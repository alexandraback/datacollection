#!/usr/bin/python

def main():
	n = 16
	s = 50

	print "Case #1:"
	form = format(n - 2, "03d") + "b"
	for i in range(min(1000000, 2**(n - 2))):
		bi = "1" + format(i, form) + "1"
		mods = []
		for base in range(2, 11):
			num = int(bi, base)
			for mod in range(2, min(num - 1, 1000)):
				if not (num % mod):
					mods.append(mod)
					break

		if len(mods) == 9:
			print bi,
			for m in mods:
				print m,
			print
			s -= 1

		if not s:
			break
	
	if s:
		print "NOT ENOUGH EXAMPLES PRODUCED!"


if __name__ == "__main__":
	main()

