from __future__ import division
'''
'''

file = open('in.txt','r')
out = open('out.txt','w')
test_cases = file.readlines()

lineId = 1
caseId = 0
while lineId < len(test_cases):
    caseId += 1
    row = test_cases[lineId].strip().split(' ')
    
    people = row[1]
    addition = 0
    prev = int(people[0])
    for i in xrange(1,len(people)):
        if i > prev:
            addition += i - prev
            prev = i
        prev += int(people[i])
        
    print >> out, "Case #%d: %d" % (caseId,addition)
    lineId += 1

file.close()
out.close()