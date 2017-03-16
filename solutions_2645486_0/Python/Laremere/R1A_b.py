fin = open("B-small-attempt1.in", "r")
fout = open("small.out", "w")


def next():
    return fin.readline().strip()
    
def nextInts():
    return map(int, next().split(" "))
    
def solve(startEnergy, endEnergy, maxEnergy, regain, activities):
    if len(activities) == 0:
        return 0
        
    print "start:", startEnergy
        
    pivot = activities.index( max(activities) )
    curEnergy = min( maxEnergy, startEnergy + regain * pivot )
    remainingActivities = (len(activities) - pivot)
    spent = max( min( curEnergy + (remainingActivities * regain) - endEnergy, curEnergy) , 0)
    result =  spent * activities[pivot]
    
    print "spent:" , spent
    
    result += solve(startEnergy, curEnergy, maxEnergy, regain, activities[: pivot ] )
    result += solve(0 + regain, endEnergy, maxEnergy, regain, activities[pivot + 1:])   #0 is wrong, but only in cases where it can't spend anyway
    
    return result
    
for case in xrange(1, int(next()) + 1):
    print case
    fout.write("Case #" + str(case) + ": ")

    mEnergy, regain, numActivities = nextInts()
    
    result = solve(mEnergy, 0, mEnergy, regain, nextInts() )
    fout.write( str( result) )
    
    fout.write('\n')

fin.close()
fout.close()