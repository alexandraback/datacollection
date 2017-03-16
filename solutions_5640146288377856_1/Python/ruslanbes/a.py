import math, sys, pdb



def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def main():

    def solve(R, C, W):
        if W == 1:
            return R*C
        coverLine = C/W
        restLine = C % W
        shoots = coverLine*(R-1)

        if C == W:
            return shoots + W
        
        shoots += coverLine
        if restLine:
            shoots += W
        else:
            shoots += W-1
        return shoots



    ############################################1
    T = int( raw_input() )
    for t in xrange(T):    
        R, C, W = map( int, raw_input().split(' ') )
        output( t, solve(R, C, W) )


if __name__ == "__main__":
   main()