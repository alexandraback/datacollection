import sys
from math import sqrt , floor , ceil
from math import log , exp
 
def transpose(mat):
	return map(list, zip(*mat))	


def addStengthToInterval(intervalOld,intervalNew,strength):
	for i in xrange(intervalNew[0],intervalNew[1]):
		intervalOld[i] = max( intervalOld[i] ,strength ) 

def wallFails(wall,interval,strength):
	for i in xrange(interval[0],interval[1]):
		if wall[i]<strength:
			return True
	return False

def solveCase(case,N):
	caseT = transpose(case)
	
	days = caseT[0]
	num_attacks = caseT[1]
	intervalsW = caseT[2]
	intervalsE = caseT[3]
	strengths = caseT[4]
	delta_days = caseT[5]
	delta_position = caseT[6]
	delta_strenght = caseT[7]
	intervals = transpose([intervalsW , intervalsE ])
	
	day = 0
	print N
	
	wall = [0]*1000
	daysToAttack=[]
	for tribe in range(N):
			daysToAttack.append(days[tribe])
			print "Tribe %d has %d attacks left" %(tribe,num_attacks[tribe])
			print "Tribe %d has %d days to attack" %(tribe,daysToAttack[tribe])
	
	count = 0
	
	while(1):
		#~ attacksRemaining=False
		intervalOld=wall[:]
		
		#~ print "day %d" %day
		
		for tribe in range(N):
			if  daysToAttack[tribe]>0 or num_attacks[tribe]==0:
				daysToAttack[tribe]-=1
				#~ print "Tribe %d has %d attacks left and %d days remaining to attack" %(tribe,num_attacks[tribe],daysToAttack[tribe])
				continue
			
			attackSuccess = wallFails(wall,intervals[tribe],strengths[tribe])
									
			#~ print "Tribe %d attacking on day %d on interval (%d,%d) with strength %d. Attack successful: %d" % (
					#~ tribe,day,intervals[tribe][0],intervals[tribe][1],strengths[tribe],attackSuccess)
			
			if attackSuccess:
				count+=1
									
			addStengthToInterval(intervalOld,intervals[tribe],strengths[tribe]) 
			
			strengths[tribe] += delta_strenght[tribe]
			intervals[tribe] = [ intervals[tribe][0] + delta_position[tribe] ,
									intervals[tribe][1] + delta_position[tribe] ]
			daysToAttack[tribe] =  delta_days[tribe] - 1
			num_attacks[tribe]-=1
			#~ print "Tribe %d has %d attacks left and %d days remaining to attack" %(tribe,num_attacks[tribe],daysToAttack[tribe])
			
			
			
		wall = intervalOld[:]
		
		day+=1
			
		if sum(num_attacks)==0 : 
			break
		
	return count
		
	
		
				
def main():
	with open(sys.argv[1]) as inFile:
		cases = []
		casesN = []
		T = int(inFile.readline())
		for i in range(T):
			cases.append([])
			N = int(inFile.readline())
			casesN.append(N)
			for j in range(N):
				cases[i].append(map(int,inFile.readline().split()))

	solutions=[]

	for index,case in enumerate(cases):
		N = casesN[index]
		solutions.append( solveCase(case,N) )
	
	

		
	with open(sys.argv[2],'w') as outFile :	
		for index,solution in enumerate(solutions):
			print solution
			outFile.write( 'Case #' + str(index+1) + ': ' + str(solution) + '\n')

if __name__ == "__main__":
    main()
