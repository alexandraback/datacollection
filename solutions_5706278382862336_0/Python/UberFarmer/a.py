import argparse
import operator

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def function(num, denom):
    # prime factor denom
    
    prime_factorz = prime_factors(denom)

    print("denom={}".format(denom))
    print("prime factors:")
    print(prime_factorz)
    
    nontwoprime = 1
    for x in prime_factorz:
        if x != 2:
            nontwoprime *= x
            
    print(nontwoprime)
    
    if num % nontwoprime: # nonzero = true
        #print("failed 1")
        return -1
    
    number = num/denom
    currentFactor = 1
    for i in range(40):
        if currentFactor <= number:
            return i
        currentFactor = currentFactor / 2
    return -1
            
                
def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        num_cases = int(f_in.readline().strip())
        for i in range(num_cases):
            num,denom = [int(x) for x in f_in.readline().strip().split('/')]
            print(num)
            print(denom)
            
            result = function(num, denom)
            
            if result == -1:
                result = "impossible"
            
            outputline = "Case #{}: {}\n".format(i + 1, result)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        