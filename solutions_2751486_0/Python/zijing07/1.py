import sys

vow = 'aeiou'

def count(str, i, j):
    max = -1
    cnt = 0
    for m in range(i, j):
	if cnt > max:
	    max = cnt
	if str[m] not in vow:
	    cnt += 1
	else:
	    cnt = 0
    if cnt > max:
	max = cnt
    return max

def calc_val(str, num):
    l = len(str)
    res, i = 0, 0
    while i < l:
	j = i+1
	while j <= l:
	    n = count(str, i, j)
	    if n >= num:
		res += 1
	    j += 1
	i += 1
    return res

def main():
    data = sys.stdin.read().split('\n')
    t = int(data[0])
    index = 1
    while t > 0:
	t -= 1

	line = data[index].split()
	str, num = line[0], int(line[1])
	res = calc_val(str, num)

	print 'Case #%d: %d' % (index, res)
	index += 1

main()
