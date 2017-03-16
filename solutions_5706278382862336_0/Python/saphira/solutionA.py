from fractions import Fraction
import pdb

def getInput(path):
    f = open(path)
    lines = f.readlines()
    f.close()
    return lines

def print_ouput():
    lines = getInput("./input.txt")
    no_cases = int(lines[0].strip())
    case = 1
    while (case<=no_cases):
        inputval = lines[case].strip()
        p = int(inputval.split("/")[0])
        q = int(inputval.split("/")[1])
        sol = get_solution(p,q)
        print "Case #{0}: {1}".format(case,sol)
        case  += 1

def get_solution(p,q):
    #pdb.set_trace()
    possible_vals = []
    frac = Fraction(p,q)
    p = frac.numerator
    q = frac.denominator
    if 2**40 % q ==0:
        generations_before = 0
        num = p
        deno = q
        while generations_before < 41:
            if float(num)/float(deno) >= 1:
                break
            num = num*2
            generations_before += 1
        return generations_before
    else:
        return "impossible"

print_ouput()

