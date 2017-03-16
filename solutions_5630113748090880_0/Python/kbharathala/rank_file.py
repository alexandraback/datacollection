def rank_and_file(l):
	dict = {}
	final_list = []
	for each in l:
		for num in each:
			dict[num] = dict[num] + 1 if num in dict else 1
	for key in dict:
		if dict[key] % 2 != 0:
			final_list.append(key)
	final_list = sorted(final_list)
	return " ".join(map(str, final_list))

f = open('B-small-attempt1.in.txt', 'r')
f2 = open('outputSmall.txt', 'w')
final = ''

for i in range(1, int(f.readline().strip())+1):
	l = []
	for j in range(2*int(f.readline()) - 1):
		l.append(map(int, f.readline().strip().split()))
	final += 'Case #{}: {}\n'.format(i, rank_and_file(l))

f2.write(final)