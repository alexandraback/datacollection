def pogo_path(x, y):
	path = ''
	if x > 0:
		path += 'WE' * x
	elif x < 0:
		path += 'EW' * -x
	if y > 0:
		path += 'SN' * y
	elif y < 0:
		path += 'NS' * -y
	return path

cases = int(raw_input())
for case in range(cases):
	x, y = map(int, raw_input().split())
	path = pogo_path(x, y)
	print 'Case #%d: %s' % (case + 1, path)