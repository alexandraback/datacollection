# Python version 2.7
#using PuLP library (https://projects.coin-or.org/PuLP) and GLPK solver (http://www.gnu.org/software/glpk/)
import sys
import pulp
import math
     
def oneCase(inputFile):
    [tx,ty] = map(int, inputFile.readline().split(' '))
    status = 0
    N = int(math.sqrt(abs(tx)) + math.sqrt(abs(ty)))-1
    while status != 1:
        N += 1
        
        solver = pulp.LpProblem("problem", pulp.LpMinimize)
        sn = [pulp.LpVariable("n"+str(i),0, 1, cat=pulp.LpInteger) for i in range(N)]
        ss = [pulp.LpVariable("s"+str(i),0, 1, cat=pulp.LpInteger) for i in range(N)]
        se = [pulp.LpVariable("e"+str(i),0, 1, cat=pulp.LpInteger) for i in range(N)]
        sw = [pulp.LpVariable("w"+str(i),0, 1, cat=pulp.LpInteger) for i in range(N)]
        #h = [pulp.LpVariable("h_"+str(i),0, 1, cat=pulp.LpInteger) for i in range(N)]
        for i in xrange(N):
            solver += sn[i] + ss[i] + se[i] + sw[i] == 1
            #if i!=0: solver += h[i] <= h[i-1]
        #solver += sum(h)
        solver += sum([(i+1)*sn[i] - (i+1)*ss[i] for i in xrange(N)]) == ty
        solver += sum([(i+1)*se[i] - (i+1)*sw[i] for i in xrange(N)]) == tx
        status = solver.solve(pulp.GLPK_CMD(msg = 0))
    r = ""
    for i in xrange(N):
        if pulp.value(sn[i]) >= 1: r+="N"
        if pulp.value(ss[i]) >= 1: r+="S"
        if pulp.value(se[i]) >= 1: r+="E"
        if pulp.value(sw[i]) >= 1: r+="W"
    return r

def main(f = None):
    inputFile = sys.stdin if f==None else open(f)
    cases = int(inputFile.readline())
    for i in range(cases):
        print "Case #" + str(i+1) + ": " + oneCase(inputFile) 

#main("B-test.in")
main()