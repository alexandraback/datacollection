fin = open('A-small-attempt1.in', 'r')
fout = open('A.out', 'w')

cases = int(fin.readline().rstrip('\n'))
# print cases

for case in xrange(1, cases+1):
	answer = 'Case #' + str(case) + ': '
	# print case
	r, c, w = [int(i) for i in fin.readline().rstrip('\n').split()]
	print r, c, w
	tries_per_line = c/w
	if c < 2*w:
		remaining = min(w, c-1)
	elif c%w == 0:
		remaining = w-1
	else:
		remaining = w
	print remaining
	answer += str(r*tries_per_line + remaining)
	print answer
	fout.write(answer+'\n')

fin.close()
fout.close()