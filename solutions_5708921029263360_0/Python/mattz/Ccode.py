import sys

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):

    # COMPUTE TOTAL NUMBER OF OUTFITS
    S = infile.readline().rstrip();

    params = S.split(' ')

    J = int(params[0])
    P = int(params[1])
    S = int(params[2])
    K = int(params[3])

    N = 0
    outfits = []

    SPcombos = {}
    JPcombos = {}
    JScombos = {}
    
    for j in range(J):
        for p in range(P):
            jp_str = str(j) + '_' + str(p)
            JPcombos[jp_str] = 0

    for j in range(J):
        for s in range(S):
            js_str = str(j) + '_' + str(s)
            JScombos[js_str] = 0

    for s in range(S):
        for p in range(P):
            sp_str = str(s) + '_' + str(p)
            SPcombos[sp_str] = 0
    for k in range(K):        
        for s in range(S):
            for p in range(P):
                for j in range(J):
                    
                    jp_str = str(j) + '_' + str(p)
                    js_str = str(j) + '_' + str(s)
                    sp_str = str(s) + '_' + str(p)
                    
                    jpflag = 0
                    jsflag = 0
                    spflag = 0
                    
                    if JPcombos[jp_str] < K:
                        jpflag = 1
                        
                    if JScombos[js_str] < K:
                        jsflag = 1
                        
                    if SPcombos[sp_str] < K:
                        spflag = 1
                    
                    if jsflag * jpflag * spflag > 0:

                        if [j,p,s] not in outfits:
                            JPcombos[jp_str] += 1
                            JScombos[js_str] += 1
                            SPcombos[sp_str] += 1
                            
                            outfits.append([j, p, s])
                            N = N + 1
                    
    # OUTPUT IN THE FORM
    print 'Case #' + str(index) + ': ' + str(N)
    
    for outfit in outfits:
        print str(outfit[0] + 1) + ' ' + str(outfit[1] + 1) + ' ' + str(outfit[2] + 1)
