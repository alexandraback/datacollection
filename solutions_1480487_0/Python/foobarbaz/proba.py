import os


#f = open("test.pa","r")

#f = open("A-small-attempt0.in","r")
f = open("A-small-attempt3.in","r")
#f = open("A-large.in","r")

s = f.readline()
ntrials = int(s)

i =0

fout = open("proba.out","w")


def bin_search(a,b,function,tol):
    #print "bin search", a,b,tol
    if (tol > (b-a)):
        return a
    val = (a+b)/2.0
    if (function(val) < 0):
        return bin_search(a, (a+b)/2.0, function,tol)
    else:
        return bin_search((a+b)/2.0, b, function,tol)

def good_enough(judges, index, val, X):
    #print "checking val ", val
    this_score = judges[index][1] + val*X
    whats_left = 1-val
    i = 0
    for j in xrange(len(judges)):
        if (j== index):
            continue
        pair = judges[j]
        probi = (this_score-pair[1])/X
        #print "prob i, j, this_score", probi, j, this_score
        if (probi < 0):
            return 1
        whats_left -= probi
        if (whats_left < 0):
            return -1
        i+=1
    #print "whats_left ", whats_left
    if (whats_left > 0):
        return 1
    return -1

def compute_val(judges,index,X,lower,upper):
    f = lambda val: good_enough(judges,index,val,X)
    val = bin_search(lower,upper,f,.00000005)
    return val

for i in xrange(1,ntrials+1):
    print "Trial", i
    line = f.readline()
    fields = line.split()
    N = int(fields.pop(0))
    judges = []
    n = 0
    print "Case #" + str(i) + ":" + "i",
    fout.write("Case #" + str(i) + ": " ) 
    X=0
    for elt in fields:
        val = int(elt)
        X+= val
        judges.append([n,val])
        n+=1

    judges.sort(lambda a,b: a[1]-b[1])
    #def bin_search(a,b,function,tol):
    #print "binary search", bin_search(0.0,10.0,lambda x:  6.3 - x , .01)
    print "Sorted", judges
    if len(judges) ==1:
        print 0
        fout.write("0 \n")
        continue;
    if X==0:
        for j in judges:
            fout.write("0 ")
        fout.write("\n")
        continue;
    results = []
    last_val = 1.0
    for j in xrange(len(judges)):
        val = compute_val(judges,j,X,0.0,last_val)
        results.append(val)
        last_val = val
        if (last_val == 0.0):
            for l in xrange(j+1,len(judges)):
                results.append(0.0)
            break

    #print "results ", results
    ordered_results = [0 for x in xrange(len(judges))]
    for j in xrange(len(judges)):
        ordered_results[judges[j][0]] = results[j]
    for j in xrange(len(judges)):
        print ordered_results[j]
        fout.write(str(100*ordered_results[j]) + " ")
    fout.write("\n")
    #judges.sort(lambda a,b: a[1]-b[1])


    
fout.close()
os.system("cat proba.out")

