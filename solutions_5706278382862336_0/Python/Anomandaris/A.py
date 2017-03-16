from IOManager import formatInput, readInput, writeOutput

number = 2**(-40)

def solve(data):
    
    results = []
    for s in data:
        t1, t2 = s.split("/");
        result = calc(float(t1),float(t2))
        results.append(result)
    
    return results
    
def calc(p,q):
    frac = p/q;
    
    if frac/number == int(frac/number):
        
        per = 1.0
        for i in range(0,40):
            if per <= frac:
                return str(i)
            else:
                per /= 2.0
    else:
        return "Impossible"

question = "A"
roundNumber = "2C"
name = "small-attempt0"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)