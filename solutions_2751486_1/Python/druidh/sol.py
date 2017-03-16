import sys
import array

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

(T,) = read_ints()
for case in range(1, T + 1):
	line, num = sys.stdin.readline()[:-1].split(' ')
	line_l = len(line)
	num = int(num)
	ans = 0

	pos = []
	for i in xrange(line_l-num+1):
		temp = line[i:(i+num)]
		if ('a' not in temp) and ('e' not in temp) and ('i' not in temp) and ('o' not in temp) and ('u' not in temp):
			pos.append(i)

#	print pos
	last_pos = 0
	for i in pos:
		i_char = i - last_pos
		ans += i_char + ((line_l - (i + num))*i_char)
#		print i, ans,
		ans += line_l - (i + num - 1)
#		print ans

		last_pos = i+1

#	for i in xrange(line_l):
#		if (i < pos[0]):
#			ans += 1 + (line_l - (pos[0] + num))

#		if (i==pos[0]):
#			ans += line_l - (i + num -1)
#		if (i >= pos[0]):
#			pos = pos[1:]

#		if (len(pos) == 0):
#			break


	print "Case #%d: %s" % (case, ans)
	

