import sys

inputpath = sys.argv[1]
outpath = sys.argv[2]

def reverse(number):
	rev = (str(number))[::-1]
	while rev and rev[0] == "0":
		rev = rev[1:]
	return int(str(rev))

with open(inputpath, "r") as f:
	out = open(outpath, "w")
	T = int(f.readline())
	for case in range(T):
		N = int(f.readline())
		steps = 1
		counted = set([1])
		check = set([1])
		while N not in check:
			tmp = set([])
			for x in check:
				if x+1 not in counted:
					tmp.add(x+1)
					counted.add(x+1)
				rev = reverse(x)
				if rev not in counted and rev > steps:
					tmp.add(rev)
					counted.add(rev)
			steps += 1
			check = tmp
			counted.remove(steps)

		out.write("Case #{}: {}\n".format(case+1, steps))
		print("Case #{}: {}".format(case+1, steps))
	out.close()
