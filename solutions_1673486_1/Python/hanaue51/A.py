'''
Created on 2012/04/28

@author: hanaue51
'''
import os
os.chdir("../../../data/2012/round1a/")
filename = "A-large"
postfix_in = ".in"
postfix_out = ".out"
format = "Case #%d: %s\n"

infile = open(os.getcwd() + "/" + filename + postfix_in, "r")
lines = infile.readlines()
infile.close()

n_cases = int(lines[0].strip())
results = []
index = 1
for i in xrange(n_cases):
    elems = lines[index].strip().split()
    index += 1
    n_already = int(elems[0])
    n_total = int(elems[1])
    probs = [float(p) for p in lines[index].strip().split()]
    index += 1
    answer = 0.0
    
    p_correct_all = 1.0
    for p in probs:
        p_correct_all *= p
    e_cost_keep_typing = n_total - n_already + 1.0 + (1.0 - p_correct_all) * (n_total + 1.0)
    e_cost_enter_rightaway = 1.0 + n_total + 1
    answer = min(e_cost_keep_typing, e_cost_enter_rightaway)
    p_correct = 1.0
    for nbs in xrange(n_already, 0, -1):
        if nbs != n_already:
            p_correct *= probs[len(probs) - nbs - 1]
        e_cost = 2.0 * nbs + n_total - n_already + 1.0 + (1 - p_correct) * (n_total + 1.0)
        if e_cost < answer:
            answer = e_cost
    
    results.append(format % (i+1, answer))

#print results
outfile = open(os.getcwd() + "/" + filename + postfix_out, "w")
for result in results:
    outfile.write(result)
outfile.close()
