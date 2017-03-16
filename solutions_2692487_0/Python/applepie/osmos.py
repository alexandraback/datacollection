from math import ceil, log

f = open('osmos.in');
out = open('osmos.out', 'w')
cases = int(f.readline());

def diff(start, end):
	if start == end:
		return 1
	return ceil(log((end-1)/(start-1), 2))

def add(start, num):
	return (start - 1) * (2** num) + 1

for CASE in range(1, cases+1):
	def calc(size, start_index):
		for i in range(start_index, num_motes):
			mote = motes[i]
			if size > mote:
				size += mote
			else:
				# two cases, remove all, or add
				num_to_add = diff(size, mote+1)
				new_size = add(size, num_to_add) + mote
				print(num_to_add, new_size)
				return min(num_motes - i, num_to_add + calc(new_size, i + 1))
		return 0

	line = f.readline().split()
	size = int(line[0])
	num_motes = int(line[1])
	motes = list(map(int, f.readline().split()))
	motes.sort()

	if size == 1:
		ans = num_motes
	else:
		ans = calc(size, 0)
	print(size, motes, ans)
	out.write("Case #{0}: {1}\n".format(CASE, ans))

