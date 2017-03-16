#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 1
problem = "B"
practice = True

if practice:
    practice = "-attempt1"
else:
    practice = ""
if case == 0:
    infile = open("%s-%s%s.in" % (problem, "sample", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "sample", practice), 'w')        
elif case == 1:
    infile = open("%s-%s%s.in" % (problem, "small", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "small", practice), 'w')    
elif case == 2:
    infile = open("%s-%s%s.in" % (problem, "large", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "large", practice), 'w')   
else:
    raise ValueError, 'Invalid case'
    
def get_min_levels(single, double):
    assert (double >= single).all()
    
    current = 0
    max_req = double.max()
    count = 0
    received = N.zeros(len(double), dtype=int)
    
    completed = False
    while not completed:
        available = (single <= current)*1 + (double <= current)*1 - received
        #print current, available
        if available.max() == 0:
            break
            
        indices = N.where(available.max() == available)[0]
        if available.max() == 1:
            #Pick first finishing up old levels 
            finishing = received[indices] == 1
            if finishing.any():
                index = indices[finishing][0]
            else:
            #Otherwise pick the highest level to get the double star
                index = indices[double[indices].max() == double[indices]][0]
        else:
            index = indices[0]
        #print len(available), index
        received[index] += available[index]
        current += available[index]
        count += 1
    
    if current < max_req:
        return "Too Bad"
    else:
        return count
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for i in range(cases):
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    levels = int(infile.readline().strip('\n'))
    single = N.empty(levels, dtype=int)
    double = N.empty(levels, dtype=int)
    for j in range(levels):
        line = infile.readline().split()
        single[j] = int(line[0])
        double[j] = int(line[1])
    #print single, double
    
    #if i == 22:
    #    break
    
    #Do calculations to generate the output
    output = get_min_levels(single, double)
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (i+1, output))
    
#Close files
infile.close()
outfile.close()