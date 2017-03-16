import sys
from Queue import Queue

ENTER = 1

def expect_reset(total):
    return 2.0 + total

def expect_backspace(bscount, probs, total):
    first_try_stroke = total + (bscount*2) - len(probs) + ENTER 
    second_try_stroke = first_try_stroke + total + ENTER
    
    first_try_prob = 1.0;
    for i in range(0, len(probs) - bscount):
        first_try_prob *= probs[i]
    
    second_try_prob = 1.0 - first_try_prob
    
    return first_try_prob*first_try_stroke + second_try_prob*second_try_stroke
     

#main
f = open(sys.argv[1], "r")
lines = f.readlines()

inputs = Queue()

for each in lines :
    inputs.put(each.replace("\n", "").replace("\r", ""))

ncase = int(inputs.get())

for i in range(0, ncase):
    print "Case #" + str(i+1) + ":",
    
    ab = inputs.get().split(" ")
    typed = int(ab[0])
    total = int(ab[1])
    
    line = inputs.get().split(" ")
    probs = map(lambda s: float(s), line)
    
    exps = []
    exps.append(expect_reset(total))
    for bscount in range(0, typed+1):
        exps.append(expect_backspace(bscount, probs, total))
    
    exps.sort();
    print exps[0]
    