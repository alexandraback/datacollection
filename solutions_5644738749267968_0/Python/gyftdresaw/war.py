
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

def naomi_wins(N,nranks,kranks):
    
    # deceit case
    # start indices at end
    nd = N - 1
    kd = N - 1
    deceit = 0
    while (nd >= 0 and kd >= 0):
        if nranks[nd] > kranks[kd]:
            deceit += 1
            nd -= 1
            kd -= 1
        else:
            kd -= 1
    
    # standard case
    ns = N - 1
    ks = N - 1
    kstandard = 0
    while (ns >= 0 and ks >= 0):
        if kranks[ks] > nranks[ns]:
            kstandard += 1
            ns -= 1
            ks -= 1
        else:
            ns -= 1

    standard = N - kstandard

    return deceit,standard


for i in xrange(trials):
    N = int(infile.readline())
    nfloats = [float(k) for k in infile.readline().split()]
    kfloats = [float(k) for k in infile.readline().split()]
    
    # sort all floats to just get ranks
    all_floats = nfloats + kfloats
    all_floats.sort()

    nranks = [j for j in xrange(2*N) if all_floats[j] in nfloats]
    kranks = [j for j in xrange(2*N) if all_floats[j] in kfloats]

    dec,stan = naomi_wins(N,nranks,kranks)
    
    s = "Case #%d: %d %d\n" % (i+1,dec,stan)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
