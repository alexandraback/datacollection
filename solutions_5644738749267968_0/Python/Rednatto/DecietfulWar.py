import sys

def solveThis( datafile ):
	numTests = int( datafile.readline() )

	numBlocks = 0

	for case in range(1,numTests+1):
		
		numBlocks = datafile.readline()
		numBlocks = numBlocks.strip()	
		numBlocks = int( numBlocks )
		
		naomi = datafile.readline()
		naomi = naomi.strip()
		naomi = naomi.split()
		tmp =[]
		for e in naomi:
			tmp.append( float( e ) )
		naomi = sorted( tmp )
		
		ken = datafile.readline()
		ken = ken.strip()
		ken = ken.split()
		tmp = []
		for e in ken:
			tmp.append( float(e ) )
		ken = sorted( tmp )
		
		if ((len(ken)!=numBlocks) or (len(naomi)!=numBlocks) ):
			sys.exit( "Read failure, wrong amount of blocks?" )
		
		war = playWar( ken, naomi, numBlocks )
		deceit = playDeceit( ken, naomi,  numBlocks )
		
		output( war, deceit, case )
		

def playWar( Ke, Na, num ):
	ki = 0
	ni = 0
	
	score = 0
	
	while ki < num:
		if Ke[ki]<Na[ni]:
			score = score+1
			ki = ki+1
		else:
			ki = ki+1
			ni = ni+1
			
	return score

def playDeceit( Ke, Na, num  ):
	score = 0
	ki = 0
	ni = findBigInd( Na, Ke[ki] )
	while ni != -1 and ni < num and ki < num:
		Na[ni] = -1
		ki = ki+1
		score = score+1
		if ki<len(Ke):
			ni = findBigInd( Na, Ke[ki] )
	return score
	
	
	
	
def findBigInd( L, val ): #sorted, so could improve with binary...
	for ind,ele in enumerate(L):
		if ele > val:
			return ind
	return -1

	
def output( war, deceit, case ):
	print( "Case #{:d}: {:d} {:d}".format( case,  deceit, war ) ) 

	
if len(sys.argv) != 2 :
	sys.exit( "Give correct files!" )

try:
	data = open( sys.argv[1], "r" )
except IOError:
	sys.exit( "Couldn't open file!" )
	
solveThis( data )

data.close()