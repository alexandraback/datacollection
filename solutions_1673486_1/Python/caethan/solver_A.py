#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 2
problem = "A"
practice = False

if practice:
    practice = "-attempt0"
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
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for i in range(cases):
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    line = infile.readline().split()
    A = int(line[0])
    B = int(line[1])
    line = infile.readline().split()
    probs = []
    for item in line:
        probs.append(float(item))
    probs = N.array(probs)
    
    #Do calculations to generate the output
    cases = N.zeros(3, dtype=float)
    
    #press enter right away
    cases[0] = B + 2 #new password + enter twice
    
    #keep typing
    prob_correct = probs.prod()
    cases[1] = prob_correct * (B - A + 1) + (1 - prob_correct) * (B - A + 1 + B + 1)
    
    #back up
    keycounts_correct = N.arange(1, A+1) * 2 + 1 + (B - A)
    keycounts_incorrect = N.arange(1, A+1) * 2 + 1 + B + 1 + (B - A)
    
    cum_correct = N.hstack((N.cumprod(probs)[-2::-1], N.array(1.)))
    
    exp_keycounts = keycounts_correct * cum_correct + keycounts_incorrect * (1 - cum_correct)
    cases[2] = exp_keycounts.min()
    
    print cases
    
    output = '%.6f' % cases.min()
    
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (i+1, output))
    
#Close files
infile.close()
outfile.close()