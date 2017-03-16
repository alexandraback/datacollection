import sys
from numpy import product

if (len(sys.argv) > 1):
	file = open(sys.argv[1],'r')
	outfile = open("output", 'w')
	cases = file.readline()
	cases = int(cases)
	iters = 0
	
	
	while(iters < cases):
		data = file.readline()
		data = data.split(' ')
		typed_chars = int(data[0])
		total_chars = int(data[1])
		
		probs = []
		data = file.readline()
		data = data.split(' ')
		for i in data:
			probs.append(float(i))
			
		answers = []
		cursor = typed_chars
		backspace = 0
		#Calculate expected value for all possibilities
		#cursor corresponds to the position of the cursor
		#after hitting the backspace key; cursor = 0 means
		#deleting all typed_chars.  backspace tracks how often
		#backspace is pressed
		while(cursor >= 0):
			success_prob = product(probs[:cursor]) #This returns 1 on empty lists
			fail_prob = 1 - success_prob
			keystrokes_succ = (total_chars - cursor) + 1 + backspace #+1 to account for pressing enter
			keystrokes_fail = keystrokes_succ + total_chars + 1
			answers.append((success_prob * keystrokes_succ) + (fail_prob * keystrokes_fail))
			cursor -= 1
			backspace += 1
			
		#Finally, add the "just press enter immediately" solution
		answers.append(total_chars + 2)
			
		
		outfile.write("Case #" + str(iters+1) + ": " + str(min(answers)) + '\n')
			
		iters += 1
		
	file.close()
	outfile.close()
		
		