import os

def determine_max_needed(max_shyness, shyness):
    shy = 0
    stood = 0
    people = 0
    for char in shyness:
	    num = int(char)
	    if shy > stood and num != 0:
		    people += shy - stood
		    stood = shy
	    #print people
	    stood += num
	    shy+=1
    #print ''
    return people 
            
with open('input.txt', 'r') as f:
    with open('output.txt', 'w') as g:
        line = f.readline()
        test_count = int(line)
        for i in range(test_count):
	    print i
        #for i in range(1):
            line = f.readline()
            max_shyness = line.split()[0]
            shyness = line.split()[1]
            g.write('Case #%s: %s\n'%(str(i+1), str(determine_max_needed(max_shyness, shyness))))
