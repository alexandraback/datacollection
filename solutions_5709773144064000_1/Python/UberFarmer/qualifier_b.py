import argparse

def cookie_calculator(C, F, X):
    cookies_per_second = 2.0
    
    # if winning is cheaper than a farm
    if (C >= X):
        # wait until we win
        return X / cookies_per_second
    else:
        # wait until we have enough cookies to buy a farm
        elapsed_time = C / cookies_per_second
        
        while (True):
            # how long will it take if we buy no farms?
            wait_time = (X - C) / cookies_per_second
            
            # how long will it take if we buy one farm?
            buy_time = X / (cookies_per_second + F)
            
            if (wait_time < buy_time):
                # wait until we win
                elapsed_time += wait_time
                return elapsed_time
            
            # buy a farm
            else:
                # increment income
                cookies_per_second += F
                
                #wait until we have C cookies again
                elapsed_time += C / cookies_per_second
                
                # do another loop
        

def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        numCases = int(f_in.readline().strip())
        for i in range(numCases):
            C, F, X = [float(n) for n in f_in.readline().strip().split()]
            
            min_time = cookie_calculator(C, F, X)

            outputline = "Case #{0}: {1:.7f}\n".format(i + 1, min_time)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        