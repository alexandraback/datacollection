from collections import deque
import sys


def solveDecWar( naomi_blocks, ken_blocks ):
	
	nscore = 0
	nb = deque( naomi_blocks )
	kb = list( ken_blocks )
	while len( nb ) > 0:
		#n should play lowest block, and say it is just lower than k's highest block, unless n's lowest block is higher than k's highest block
		nc = nb.popleft()
		kc = 0
		
		if nc > kb[0]:
			kc = kb[0]
			kb.remove( kc )
			
		else:
			kc = kb[-1]
			kb.remove( kc )
			
		if nc > kc:
			nscore += 1
	
	return nscore

def solveWar( naomi_blocks, ken_blocks ):
	
	nscore = 0
	nb = deque(naomi_blocks )
	kb = list( ken_blocks )
	while len( nb ) > 0:
		#n should always play lowest block_count
		#k should play the lowest block higher than n, or lowest block if he can't beat it
		nc = nb.popleft()
		kc = 0
		if kb[-1] < nc: #if ken's biggest block can't beat naomi, play lowest block
			kc = kb[0]
			kb.remove( kc )
		else:
			kc = min( [x for x in kb if x > nc] )
			kb.remove( kc )
		
		if nc > kc:
			nscore += 1
			
	return nscore

def solve(infile):
	output = ""
	t_count = int( infile.readline() )
	
	for t in range( t_count ):
		block_count = int( infile.readline() )
		naomi_input = infile.readline().strip().split( " " )
		naomi_blocks = [float(x) for x in naomi_input]
		naomi_blocks.sort()
		
		ken_input = infile.readline().strip().split( " " )
		ken_blocks = [float(x) for x in ken_input]
		ken_blocks.sort()
		
		war_score = solveWar( naomi_blocks, ken_blocks )
		dec_war_score = solveDecWar( naomi_blocks, ken_blocks )
		
		output += "Case #{}: {} {}\n".format( t+1, dec_war_score, war_score )
		
	return output.strip()

if( __name__ == "__main__" ):
	infile_name = sys.argv[1]
	
	output = "__null__"
	with open( infile_name ) as f:
		output = solve( f )
		
	with open( infile_name + ".out", "w" ) as of:
		of.write( output )
	
	exit(0)