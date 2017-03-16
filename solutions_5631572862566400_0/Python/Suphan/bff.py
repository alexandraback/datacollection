f = open('C-small-attempt0.in')
fw = open('C-small.out', 'w')

cases = int(f.readline())
for case in range(cases):
	N = int(f.readline())
	bff = map(int, f.readline().split())
	circle = []
	line1 = {}
	line2 = {}

	for i in range(N):
		start = i
		used = {}
		used[i] = 1
		current = i
		count = 1
		while True:
			next = bff[current] - 1
			if next == start:
				circle.append(count)
				break
			if next in used:
				circle.append(-1)
				break
			used[next] = 1
			current = next
			count += 1

	for i in range(N):
		used = {}
		used[i] = 1
		prev = -1
		current = i
		count = 1
		while True:
			next = bff[current] - 1
			if next == prev:
				key = (prev, current)
				if prev < current:
					if key not in line1 or line1[key] < count:
						line1[key] = count
				else:
					if key not in line2 or line2[key] < count:
						line2[key] = count
				break
			if next in used:
				#line.append(-1)
				break
			used[next] = 1
			prev = current
			current = next
			count += 1

	#print 'circle ', circle
	#print 'line1 ', line1
	#print 'line2 ', line2
	max_circle = max(circle)
	max_line = 0
	for key1 in line1:
		key2 = (key1[1], key1[0])
		max_line += line1[key1] + line2[key2] - 2
	ans = max(max_circle, max_line)
	#print ans
	fw.write('Case #' + str(case + 1) + ': ' + str(ans) + '\n')

fw.close()
f.close()
