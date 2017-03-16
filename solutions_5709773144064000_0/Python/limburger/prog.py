import sys

def solve(infile):
	output = ""
	t_count = int( infile.readline() )
	
	for t in range( t_count ):
		cps = 2 # cookies per second
		parts = infile.readline().strip().split( " " )
		( farm_cost, farm_yield, win_score ) = [float(x) for x in parts]
		
		win_time = win_score / cps
		latest_farm_time = 0
		max_farms = int( win_score / farm_cost )
		
		for i in range( max_farms ):
			latest_farm_time += farm_cost / cps
			cps += farm_yield
			new_win_time = latest_farm_time + win_score / cps
			
			if( new_win_time < win_time ):
				win_time = new_win_time
		
		
		output += "Case #{}: {}\n".format( t+1, win_time )
		
	return output.strip()

if( __name__ == "__main__" ):
	infile_name = sys.argv[1]
	
	output = "__null__"
	with open( infile_name ) as f:
		output = solve( f )
		
	with open( infile_name + ".out", "w" ) as of:
		of.write( output )
	
	exit(0)