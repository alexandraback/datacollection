"""
Google Code Jam
Online Qualifying Round

Problem B - Cookie Clicker Alpha

Given the cost of a farm, the production rate
of a farm, and the winning total, find the minimum
time it takes to get there.
"""

# Files
INFILENAME = 'B-large.in'
OUTFILENAME = 'B-large.out'

infile = open(INFILENAME)
cases = int(infile.readline())

outfile = open(OUTFILENAME, 'w')

for case in range(1,cases+1):    
    farmcost, farmbonus, wincost = (float(x) for x in infile.readline().split())
    
    timepassed = 0
    
    cps = 2
    
    farming = True
    while farming:
        idletime = wincost / cps
        farmtime = farmcost / cps
        
        # Will buying this farm improve my time?
        newcps = cps + farmbonus
        longtermtime = farmtime + ( wincost / newcps)
        
        if longtermtime < idletime:
            # Yes! Buy the farm!
            cps = newcps
            timepassed += farmtime
        else:
            # No! Quit while you're ahead!
            timepassed += idletime
            farming = False
        
    outfile.write("Case #{}: {:.7f}\n".format(case, timepassed))
            
    
    