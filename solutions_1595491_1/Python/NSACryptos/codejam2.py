import math


def test(score, p):
    if score >= 3*p-2:
        return 0
    if (score <= 3*p-5) or (score < 2):
        return 1
    return 2

filename = "B-large.in"
outputN   = "codejam2.txt"

def solve(N,S,p,t, case):
    output = 0
    sur = 0
    for i in range (0,len(t)):
        if test(int(t[i]),p)==0:
            output = output+1
        if test(int(t[i]),p)==2:
            sur = sur + 1
    if sur <= S:
        output = output + sur
    else :
        output = output + S


    fi.write("Case #" + str(case) +": " + str(output)+ "\n") 
fi = open(outputN, 'r+')
def read(filename):

    f = open(filename)
    line = f.readline()
    line = line.strip()
    T = int(line)
    case = 0
    for l in f:
        case = case + 1
        l = l.strip()
        l = l.split(' ')
        N = int(l[0])
        S = int(l[1])
        p = int(l[2])
        t = l[3:]
        solve(N,S,p,t, case)
    f.close()
    fi.close()
    
        


    
