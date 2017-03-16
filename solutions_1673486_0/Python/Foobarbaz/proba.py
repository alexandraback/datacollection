import os


#f = open("test.pa","r)"

f = open("A-small-attempt0.in","r")

s = f.readline()
ntrials = int(s)

i =0

fout = open("proba.out","w")

def fail_probs(probs,A,B):
    succeed = 1.0;
    f_upto = []
    for elt in probs:
        succeed = elt*succeed
        f_upto.append(1.0-succeed)
    return f_upto

def do_over(probs,A,B):
    return B

def expected_upto(probs,A,B):
    fails = fail_probs(probs,A,B)
    expected = []
    print "A,probs", A, probs,fails
    assert (A == len(probs))
    for i in xrange(A):
        expected.append((A-B) + 2*(B-(i+1)) + fails[i]*(B))
    return expected

def min_arr(foo):
    val = 1000001
    for elt in foo:
        if (val > elt):
            val = elt
    return val

for i in xrange(1,ntrials+1):
    line = f.readline()
    fields = line.split()
    A = int(fields.pop(0))
    B = int(fields.pop(0))+1
    line = f.readline()
    fields = line.split()
    probs = []
    for elt in fields:
        probs.append(float(elt))
    exp = expected_upto(probs,A,B)
    print "expected", exp
    val1 = min_arr(exp)
    if ((B+1)*1.0 < val1):
        val1 = (B+1)*1.0
    
    print "Val is ", val1;
    fout.write("Case #" +str(i) + ": " + str(val1) +"\n")
    
fout.close()
os.system("cat proba.out")

