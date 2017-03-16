import fileinput
import logging
import sys

logging.basicConfig(stream=sys.stderr,level=logging.DEBUG)

nTest = 0
line_no = 0
instances = []

first_instance_line = True

instance_line = 0 

for line in fileinput.input():
    if line_no == 0:
        nTest = int(line)
        logging.debug("%d" % nTest)
    else:
        if instance_line == 0:
            instance_line +=1
            a = line.split()
            (K,L,S) = (int(a[0]),int(a[1]),int(a[2]))
        elif instance_line == 1:
            instance_line +=1
            Keyboard = line.rstrip()
        else:
            instance_line = 0
            pattern = line.rstrip()
            instances.append((K,L,S, Keyboard, pattern))
            


    line_no+=1

memo = {}

def table(j,i,preds,S):
    if (j,i) in memo:
        return(memo[(j,i)])
    if i==0:
        if j == 0:
            return 0
        else:
            return -2000
    else:
        if j==0:
            val = table(0,i-1,preds,S)
            if (i >= len(S)):
                val = max(val,table(0,i-len(S),preds,S)+1)
                val = max(val,table(len(S)-1,i-1,preds,S)+1) 
        else:
            val = table(j-1,i-1,preds,S)
            if (preds[j] > 0):
                val = max(val,table(len(S)-1,i-1,preds,S)+1)
        logging.debug("j %d i %d" %(j,i))
        logging.debug(val)
        memo[(j,i)] = val
        return val
            
def compute_pred(S):
    preds = [-1 for x in xrange(len(S))]
    for j in xrange(1,len(S)):
        logging.debug("to j %d" % (j))
        logging.debug("to j %s from j %s" % (S[0:j], S[len(S)-j:]))
        if S[0:j] == S[len(S)-j:]:
            preds[j] = len(S)-j
    logging.debug(preds)
    return preds

def expected(pat,key):
    counts = {}
    for i in xrange(len(key)):
        x = key[i]
        if x in counts:
            counts[x] = counts[x] +1
        else:
            counts[x] = 1
    prob = 1.0
    den = len(key)*1.0
    for x in pat:
        if x in counts:
            prob = prob*((1.0*counts[x])/den)
        else:
            return 0.0
    logging.debug(counts)
    return prob*(len(pat)+1-len(key))

def instance(inst):
    (K,L,S, Keyboard, Pattern) = inst
    for x in Pattern:
        if not x in Keyboard:
            return 0
    preds = compute_pred(Pattern)
    memo.clear()
    val = table(0,S,preds,Pattern)
    logging.debug("val %d" % val)
    exp_value = expected(Pattern,Keyboard)
    logging.debug("expected %f" % exp_value)
    return val-exp_value

out_line_no = 1
for x in instances:
    print "Case #%d: %d" % (out_line_no, instance(x))
    out_line_no+=1



