import sys

time = {}
walls = {}
att = []

def handle(line):
    l = [int(i) for i in line.split()]
    return l

def init_time():
    l = len(att)
    for i in range(l):
	attack = att[i]
	for j in range(attack[1]):
	    day = attack[0] + j*attack[5]
	    if day in time:
		tripe = time[day]
		tripe.append(i)
		time[day] = tripe
	    else:
		tripe = [i]
		time[day] = tripe

def defend(attacks):
#    print attacks
    res = 0
    height = -1
    bw = []
    for a in attacks:
	w,e,s = a[2], a[3], a[4]
	d = 0
#	print w, e
	for i in range(w, e):
	    if s > height:
		height = s
	    if s == 0:
		continue
	    if i in walls:
		if s > walls[i]:
#		    print 'smaller walls'
		    bw.append(i)
		    d = 1
	    else:
#		print 'no walss'
		bw.append(i)
		d = 1
	res += d

	#move
	a[2] += a[6]
	a[3] += a[6]
	a[4] += a[7]

    for i in bw:
	walls[i] = height
	
    return res

def emulate():
    init_time()
    res = 0
    for t in time.keys():
#	print 'day', t
	attacks = [att[i] for i in time[t]]
	d = defend(attacks)
#	print d
	res += d
    return res

def main():
    data = sys.stdin.read().split('\n')
    t = int(data[0])
    index = 1
    for k in range(1, t+1):
	att[:] = []
	time.clear()
	walls.clear()
	n = int(data[index])
	index += 1
	for i in range(n):
	    att.append(handle(data[index]))
	    index += 1

	res = emulate()

	print 'Case #%d: %d' % (k, res)
    
main()
