#!/usr/bin/python


def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(own, m):
	op = 0
	motes = sorted(m)	
	if own == 1:
		return len(motes)

	bestcost = 1000000000
	for i in range(len(motes)+1):
		s = own
		eaten = 0
		cost = len(motes)-i
		while True:
			start = eaten
			#print('Doing range ' + str(start) + ', ' + str(i))
			for mote in motes[start:i]:
				if mote >= s:
					#print('Need to grow')
					break
				else:
					s += mote
					eaten += 1
					#print('Ate ' + str(mote))
			else:
				if bestcost > cost:
					#print('New best ' + str(cost))
					bestcost = cost
				break
			cost += 1
			s = s*2-1
			#print('Growing to' + str(s))
		#print('One done')
	return bestcost

cases = readint()
for k in range(cases):
	own, others = readarray(int)
	motes = readarray(int)
	#print('Read one case')
	print('Case #' + str(k+1) + ': ' + str(solve(own, motes)))
