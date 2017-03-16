from math import ceil

def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res

def readlinearray(foo): return map(foo, raw_input().split())


f_out = open('B-small-practice.out', 'w')
f_out = open('A-large-practice.out', 'w')

def write_output(file_out, case_nr, minutes):
    output_string = "Case #" + str(case_nr) + ": " 
    output_string += str(minutes)
    output_string += "\n"
    file_out.write(output_string)


T =  readint()


## Takes a list of the number of pancakes on a plate and generates a histogrma
## with how many plates that are with specific number of pancakes.
def get_hist(plates):
    M = max(plates)
    print "M is ", M
    hist = [0] * (M+1)
    for plate in plates:
        hist[plate] += 1

    print "the histogram of these plates is ", hist
    return hist

## Takes a histogram of pancake distribution and finds how many there are larger
## than a certain number.     
def get_larger_than(hist):
    N = len(hist)
    larger_than = [0] * N 
    current = 0
    print "hist is ", 
    print hist
    for i in reversed(range(N)):
        current += hist[i]
        larger_than[i] = current
        
    
    print "our larger than hist is ",
    print larger_than
    return larger_than

## Finds the cost of halving all the pancake piles above each threshhold

def cost_of_cutting(hist):
    N = len(larger_than)
    cost = [0] *  N
    ## 
    for cutoff in range(1,N):
        for i in range(1,len(hist)):
            cost[cutoff] += hist[i] * (ceil(float(i)/cutoff) -1)
            #print "i and cutoff are ", i, cutoff, " and the result is " ,ceil(float(i)/cutoff) - 1
        cost[cutoff] += cutoff
    cost[0] += 123456789 # since we can never cut 
    print "the cost of each cut is", cost 
    #print "when hist is ", hist
    return cost
    
    
## OKay so my idea is relatively simple. We first order the 
## number of pancakes on each plate into a histogram. 
## Then we make a table of the number of plates with more than N pancakes.
## So that if there are 4 plates with 7, and 2 wiht 9 (and these
## are the largest values) then we  get ...4 2 2].

## Aaah this won't work because sometimes we will need to cut a pile several times. Boo boo. 
## I guess I should just write an iterative type solution?
## So we will just need to use the histogram straight up. 

## We can find the cost to get every pile below a certain level
## the cost for a pile of height H to get below B is ceil(H/B)

for test_case in range(T):
    D = readint()
    plates = readlinearray(int)
    print "D and plates are ", D, plates
    hist = get_hist(plates)
    
    larger_than = get_larger_than(hist)
    
    cost = cost_of_cutting(hist)
    result = int(min(cost))
    print "RESULT IS ", result, "\n"
    
    write_output(f_out, test_case + 1, result)
