n_cases = input()

def solve():
	height,width = map(eval,raw_input().split(' '))
	lawn = [map(eval,raw_input().split(' ')) for y in range(height)]
	lawn_t = zip(*lawn)
	cut_lawn = []
	cut_lawn_t = []
	for y in range(height):
		cut_lawn.append([max(lawn[y])]*width)
	for x in range(width):
		cut_lawn_t.append([max(lawn_t[x])]*height)
	cut_lawn_t
	cut_lawn = [[min(cut_lawn[y][x],cut_lawn_t[x][y]) for x in range(width)]for y in range(height)]
	if cut_lawn == lawn:
		return 'YES'
	else:
		return 'NO'
		

for case in range(1,n_cases+1):
	print 'Case #'+`case`+': '+solve()