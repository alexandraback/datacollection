filename = "A-large.in"
outputN  = "codejamR1-1out.txt"
fi = open(outputN, 'r+')

def solve (A, B, p, case):
    result = B+2
    for k in range (0,A+1):
        product = prod(p,A-k)
        prob = product*(2*k+B-A+1)+(1-product)*(2*k+2*B+2-A)
        if prob < result:
            result = prob
    fi.write("Case #" + str(case) +": " + str(result)+ "\n")

def prod(p,k):
    result = 1
    for i in range (0,k):
        result = result*float(p[i])
    return result

def read(filename):

    f = open(filename)
    line = f.readline()
    line = line.strip()
    T = int(line)
    case = 0
    
    for i in range (0,T):
        case = case + 1
        l = f.readline()
        l = l.strip()
        l = l.split(' ')
        A = int(l[0])
        B = int(l[1])

        l = f.readline()
        l = l.strip()
        l = l.split(' ')
        p = l

        solve(A, B, p, case)
    f.close()
    fi.close()
