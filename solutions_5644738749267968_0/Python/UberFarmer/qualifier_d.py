import argparse

def regular_scorer(naomi_points, num_blocks, naomi_blocks, ken_blocks):
    if (num_blocks == 0):
        return naomi_points
    naomi_block = naomi_blocks.pop(0)
    
    ken_wins = False
    for i in range(num_blocks):
        if ken_blocks[i] > naomi_block:
            ken_wins = True
            break
    if (ken_wins):
        del ken_blocks[i]
        return regular_scorer(naomi_points, num_blocks - 1, naomi_blocks, ken_blocks)
    else:
        del ken_blocks[0]
        return regular_scorer(naomi_points + 1, num_blocks - 1, naomi_blocks, ken_blocks)
        
def deceitful_scorer(naomi_points, num_blocks, naomi_blocks, ken_blocks):
    if (num_blocks == 0):
        return naomi_points

    naomi_block = naomi_blocks.pop(0)
    if (naomi_block > ken_blocks[0]):
        # beat his smallest
        del ken_blocks[0]
        return deceitful_scorer(naomi_points + 1, num_blocks - 1, naomi_blocks, ken_blocks)
    elif (naomi_block < ken_blocks[0]):
        # take out his biggest
        del ken_blocks[-1]
        return deceitful_scorer(naomi_points, num_blocks - 1, naomi_blocks, ken_blocks)
        
        
def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        num_cases = int(f_in.readline().strip())
        for i in range(num_cases):
            num_blocks = int(f_in.readline().strip())
            print(num_blocks)
            naomi_blocks = [float(b) for b in f_in.readline().strip().split()]
            naomi_blocks.sort()
            print(naomi_blocks)
            ken_blocks = [float(b) for b in f_in.readline().strip().split()]
            ken_blocks.sort()
            
            naomi_regular_score = regular_scorer(0, num_blocks, naomi_blocks[:], ken_blocks[:])
            
            naomi_deceitful_score = deceitful_scorer(0, num_blocks, naomi_blocks[:], ken_blocks[:])
            
            outputline = "Case #{}: {} {}\n".format(i + 1, naomi_deceitful_score, naomi_regular_score)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        