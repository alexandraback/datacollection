import sys

import psyco; psyco.full()

valid = 0

def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x
    
def solve(sofar, cars, used, depth):
    global valid
    if depth == len(cars):
        newcar = ""
        for c in sofar:
            if len(newcar) == 0 or newcar[-1] != c:
                newcar = newcar + c
        
        seen = {}
        for c in newcar:
            if c in seen:
                return
            seen[c] = True
            
        #print "cand", sofar
        valid += 1
    else:
        for i in xrange(len(cars)):
            if not used[i]:
                newused = list(used)
                newused[i] = True
                solve(sofar + cars[i], cars, newused, depth+1)
def main():
    global valid
    pows = [1]
    for i in xrange(1, 41):
        pows.append(pows[i-1] * 2)
        
    #print pows
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        ncars = int(f.readline())
        cars = f.readline().strip("\r\n").split()
        
        newcars = []
        for car in cars:
            newcar = ""
            for c in car:
                if len(newcar) == 0 or newcar[-1] != c:
                    newcar = newcar + c
                    
            newcars.append(newcar)
            
        cars = newcars
        
        inside = {}
        for car in cars:
            if len(car) > 2:
                for i in xrange(1, len(car)-1):
                    inside[car[i]] = True
        
        bad = False
        for car in cars:
            if car[0] in inside or car[-1] in inside:
                bad = True
                break
                
        if bad:
            valid = 0
        else:
            valid = 0
            solve("", cars, [False] * len(cars), 0)

        print "Case #%d: %d" % (caseno+1, valid % 1000000007)
        
main()