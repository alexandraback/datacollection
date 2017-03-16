import sys

def solveThis( datafile ):
	numTests = int( datafile.readline() )

	goal = 0
	increase = 0
	cost = 0
	row = None
	
	for case in range(1,numTests+1):
		row = datafile.readline()
		
		row = row.strip()
		row = row.split()
		cost = float( row[0] )
		increase = float( row[1] )
		goal = float( row[2] )
		
		answer = calculate( cost, increase, goal )
		output( answer, case )

def calculate( cost, increase, goal ):
	total = 0.0
	incr = 2.0
	
	toGoal = 0
	while True:
		toGoal = distance( 0, goal, incr )
		toFarm = distance( 0, cost, incr )
		
		if toGoal<toFarm:
			return total+toGoal
		
		toGain = intersection( incr, incr+increase, cost )
		
		if (toFarm+toGain)<toGoal:
			total = total+toFarm
			incr = incr + increase
		else:
			return total+toGoal	
		
		
	
def distance( curr, goal, inc ): #No flat!
	return float(goal-curr) / inc

	
def intersection( incA, incB, AminusB ): #No parallel!
	return AminusB / float( incB - incA ) 


def output( answer, case ):
	print( "Case #{:d}: {:.7f}".format( case, answer ) ) 


if len(sys.argv) != 2 :
	sys.exit( "Give correct files!" )

try:
	data = open( sys.argv[1], "r" )
except IOError:
	sys.exit( "Couldn't open file!" )
	
solveThis( data )

data.close()