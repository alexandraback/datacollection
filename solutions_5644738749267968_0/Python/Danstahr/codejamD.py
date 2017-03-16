cases = int(raw_input())

def fake(first, second, n):
	fb, sb = 0, 0
	fe, se = n-1, n-1
	count = 0
	for i in range(0, n):
		if first[fb] < second[sb]:
			fb += 1
			se -= 1
		else:
			fb += 1
			sb += 1
			count += 1
	return count

def fair(first, second, n):
	fb, sb = 0, 0
	fe, se = n-1, n-1
	count = 0
	for i in range(n):
		if first[fe] > second[se]:
			sb += 1
			fe -= 1
			count += 1
		else:
			se -= 1
			fe -= 1
	return count
		

for case in range(1, cases + 1):
	n = int(raw_input())
	first = map(float, raw_input().split())
	second = map(float, raw_input().split())
	first.sort()
	second.sort()
	print "Case #%d:" % case,fake(first, second, n), fair(first, second, n)
	
