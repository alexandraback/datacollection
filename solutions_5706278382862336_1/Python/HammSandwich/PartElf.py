# success in small and large sample inputs

from CodeJamHelper import CodeJamHelper

def main():
    h = CodeJamHelper("A-large")    
    
    t = h.nextInt()

    for x in range(t):
        h.output(process(h.nextDelimitedLine("/")))

twoForty = 1099511627776

def process(line):
    n = int(line[0])
    d = int(line[1])
    success, n, d = factorNonTwos(n,d)
    if not success:
        return "impossible"
    
    checkD = 2
    generation = 1
    while checkD <= d:
        responsibility = (d/checkD)
        if(n >=responsibility ):
            return generation
        checkD *=2
        generation += 1
    
    #while d < twoForty:
        
    
    return str(n) + "/" + str(d) + " " + str(generation)

def factorNonTwos(n,d):
    otherprimes = d
    while otherprimes % 2 == 0:
        otherprimes = otherprimes /2
    if n % otherprimes != 0 or d % otherprimes != 0:
        return False, 0, 0
    return True, n / otherprimes, d / otherprimes

    
if __name__ == "__main__":
    main()