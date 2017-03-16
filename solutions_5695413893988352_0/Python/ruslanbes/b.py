import math, sys



def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def solve(inC, inJ, inCmpCJ, inI):
    #print 'in=', inC, inJ, inCmpCJ
    C = inC[:]
    J = inJ[:]
    l = len(C)
    cmpCJ = inCmpCJ  # 1 - J > C, -1 - J < C
    solutions = []
    for i in xrange(inI, l):
        #if inCmpCJ > 0:
            #print 'cmp', i,C[i],J[i], cmpCJ
        if C[i] == '?' and J[i] == '?':
            if cmpCJ == 0:
                C1 = C[:]
                C1[i] = '1'
                J1 = J[:]
                J1[i] = '0'
                C1, J1 = solve(C1, J1, -1, i+1)
                solutions.append([C1, J1])
                

                C2 = C[:]
                C2[i] = '0'
                J2 = J[:]
                J2[i] = '1'
                C2, J2 = solve(C2, J2, 1, i+1)
                solutions.append([C2, J2])

                C[i] = '0'
                J[i] = '0'
            elif cmpCJ > 0:
                C[i] = '9'
                J[i] = '0'
            else: 
                C[i] = '0'
                J[i] = '9'

        elif C[i] != '?' and J[i] != '?':
            if cmpCJ == 0:
                cmpCJ = int(J[i]) - int(C[i])
        elif C[i] == '?':
            if cmpCJ == 0:
                if int(J[i]) < 9:
                    C1 = C[:]
                    C1[i] = str( int(J[i])+1 )
                    J1 = J[:]
                    C1, J1 = solve(C1, J1, -1, i+1)
                    solutions.append([C1, J1])
                
                if int(J[i]) > 0:
                    C2 = C[:]
                    C2[i] = str( int(J[i])-1 )
                    J2 = J[:]
                    C2, J2 = solve(C2, J2, 1, i+1)
                    solutions.append([C2, J2])

                C[i] = J[i]
            elif cmpCJ > 0:
                C[i] = '9'
            else:
                C[i] = '0'
        else:
            if cmpCJ == 0:

                if int(C[i]) > 0:
                    C2 = C[:]
                    J2 = J[:]
                    J2[i] = str( int(C[i])-1 )
                    C2, J2 = solve(C2, J2, -1, i+1)
                    solutions.append([C2, J2])

                if int(C[i]) < 9:
                    C1 = C[:]
                    J1 = J[:]
                    J1[i] = str( int(C[i])+1 )
                    C1, J1 = solve(C1, J1, 1, i+1)
                    solutions.append([C1, J1])

                J[i] = C[i]
            elif cmpCJ > 0:
                J[i] = '0'
            else:
                J[i] = '9'

    C = ''.join(C)
    J = ''.join(J)
    if len(solutions) == 0:
        return C, J

    solutions.append([C,J])
    #print 'solutions', solutions
    diffs = []
    for s in solutions:
       #print 's=',s
        intC = int( s[0] )
        intJ = int( s[1] )
        diffs.append([abs(intC-intJ), intC, intJ, s[0], s[1]])

    diffs.sort(key=lambda d: d[2] )
    diffs.sort(key=lambda d: d[1] )
    diffs.sort(key=lambda d: d[0] )
    #print 'diffs=', diffs
    return diffs[0][3], diffs[0][4]


def main():


    ############################################1
    T = int( raw_input() )
    for t in xrange(T):    
        C, J = map(list, raw_input().split())

        outC, outJ = solve(C, J, 0, 0)
        output(t, outC + ' ' + outJ)




if __name__ == "__main__":
   main()