T = int(raw_input())
for t in range(1, T+1):
	a, b = map(float, raw_input().split())
	pl  = map(float, raw_input().split())
	siz = len(pl)
	p = reduce(lambda x,y:x*y, pl)
	p1 = [pl[0]]
	for i in range(1, siz):
		p1.append(p1[i-1] * pl[i])
	
	keep_typing = (b-a+1)*p + (2*b-a+2)*(1-p)
	press_enter = (b+2)
	
	strokes = [keep_typing, press_enter]
	for i in range(1, int(a)+1):
		# press backspace i times
		good = 2*i + (b-a) + 1
		bad  = 2*i + (b-a) + 1 + b + 1
		rel = p1[siz-i]
		strokes.append(good*rel + bad*(1-rel))
	
	print "Case #{0}: {1:.6f}".format(t, min(strokes))
