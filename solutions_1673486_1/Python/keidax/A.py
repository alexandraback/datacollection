'''
Google Code Jam 2012, Round 1A
Created on Apr 27, 2012

@author: Gabriel D. Holodak
'''
import math
fin = open('A-large.in')
fout = open('output.txt', 'w')
num_cases = int(fin.readline().strip())
def most_efficient_backspace(A,B,probs):
    leng=len(probs)
    lowest=3*B+3
    prob_correct=1
    #print 'a=',A
    for num in range(A,-1,-1):
        #print num
        if(leng-1-num>=0):
            prob_correct*=probs[leng-1-num]
        #print (2*num+B-A+1),(2*num+(B-A)+1+B+1)
        #print prob_correct
        #print probs[:len(probs)-num]
        #print prob_correct*(2*num+B-A+1),(1-prob_correct)*(2*num+(B-A)+1+B+1)
        lowest=min(lowest,prob_correct*(2*num+B-A+1)+(1-prob_correct)*(2*num+(B-A)+1+B+1))
    return lowest
for i in range(num_cases):
    output_string = 'Case #'+str(i+1)+": "
    
    limits = fin.readline().strip().split()
    A = int(limits[0])
    B = int(limits[1])
    probs_as_strings = fin.readline().strip().split()
    probs =[]
    for prob in probs_as_strings:
        probs+=[float(prob)]
    prob_correct=1
    for prob in probs:
        prob_correct*=prob
    #keystrokes_if_keep_typing=prob_correct*(B-A+1)+(1-prob_correct)*((B-A)+1+B+1)
    keystrokes_if_press_enter=1+B+1
    keystrokes_if_backspace=most_efficient_backspace(A,B,probs)
    #print output_string,"press enter",keystrokes_if_press_enter,"backspace",keystrokes_if_backspace
    output_string+=str(min(keystrokes_if_press_enter,keystrokes_if_backspace))
    print output_string
    fout.write(output_string+'\n')
fout.close()
fin.close()
