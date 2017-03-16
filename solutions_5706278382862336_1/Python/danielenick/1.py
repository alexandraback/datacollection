import sys,math

cases = int(raw_input())
plays = []

def is_possible(p,q):
	a = (math.pow(2,40)*p % q)

	return a==0

for i in range(cases):
    plays.append(raw_input())

case = 0
for play in plays:
    case += 1
    pq = play.split('/')
    p = float(pq[0])
    q = float(pq[1])

    val = q/p

    if is_possible(p,q):
		i = 0
		while val > math.pow(2,i):
			i+=1
		sys.stdout.write("Case #"+str(case)+": "+ str(i))
		print ""
    else:
		sys.stdout.write("Case #"+str(case)+": impossible")
		print ""