'''
Created on 2013/04/27

@author: hanaue51
'''

import os
import math

os.chdir("../../../data/2013/round1a/")
filename = "A-large"
postfix_in = ".in"
postfix_out = ".out"
results = []
format = "Case #%d: %s\n"

def black_rings(radius, paint):
    rings = (paint + 3 - 2 * radius) / 4
    
#    while True:
#        if paint_required > paint:
#            paint_required -= 4 * rings + 2 * radius - 3
#            rings -= 1
#        else:
#            break
    
    x = (math.sqrt((2.0 * radius - 1.0) ** 2.0 + 8.0 * paint) - 2.0 * radius + 1.0)
    n = int(math.floor(x)) / 4
    
    if (n + 1) * (2 * (n + 1) + 2 * radius - 1) <= paint:
        rings = n + 1
    elif n * (2 * n + 2 * radius - 1) <= paint:
        rings = n
    else:
        rings = n - 1
    
    return rings

# read inputs
infile = open(os.getcwd() + "/" + filename + postfix_in, "r")
lines = infile.readlines()
infile.close()

cases_count = int(lines[0].strip())
for i in xrange(cases_count):
    elements = lines[i + 1].strip().split()
    radius = int(elements[0])
    paint = int(elements[1])
    results.append(format % (i + 1, black_rings(radius, paint)))

# write results
outfile = open(os.getcwd() + "/" + filename + postfix_out, "w")
for result in results:
    outfile.write(result)
outfile.close()
