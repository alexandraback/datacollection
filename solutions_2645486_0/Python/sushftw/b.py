import sys
import math

def solve(currE, E, R, N, vals):
				if (N == 0):
								return (0, [])
				maxGain = -1
				maxEnergy = None
				maxRestEnergies = None
				for e in range(currE+1):
								gain = e*vals[0]
								(restGain, restEnergies) = solve(min(E, currE-e+R), E, R, N-1, vals[1:])
								gain += restGain
								if (gain > maxGain):
												maxEnergy = e
												maxRestEnergies = restEnergies
												maxGain = gain
				maxRestEnergies.insert(0, maxEnergy)
				return (maxGain, maxRestEnergies)
			
lines = [x.strip() for x in open(sys.argv[1]).readlines()]
numCases = int(lines[0])
lines = lines[1:]
for i in range(numCases)[:]:
				(E, R, N) = map(int, lines[i*2].split())
				vals = map(int, lines[i*2+1].split())
				(maxGain, energies) = solve(E, E, R, N, vals)
				print "Case #%d: %d" % ((i+1), maxGain)
				
